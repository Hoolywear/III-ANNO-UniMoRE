from django.urls import reverse_lazy, reverse
from .models import *
from django.views.generic.list import ListView
from django.views.generic.detail import DetailView
from django.views.generic.edit import CreateView
from django.shortcuts import get_object_or_404, redirect, render
from .forms import *


# Create your views here.

class IndexViewList(ListView):
    model = Question
    template_name = 'polls/index.html'

    def get_queryset(self):
        return self.model.objects.order_by('-pub_date')[:20]


class DetailQuestion(DetailView):
    model = Question
    template_name = "polls/detail.html"


def search(request):
    if request.method == "POST":
        form = SearchForm(request.POST)
        if form.is_valid():
            sstring = form.cleaned_data.get("search_string")
            where = form.cleaned_data.get("search_where")
            # importa redirect da django.shortcuts
            return redirect("polls:searchresults", sstring, where)
    else:
        form = SearchForm()

    return render(request, template_name='polls/searchpage.html', context={'form': form})


class SearchResultsList(ListView):
    model = Question
    template_name = "polls/searchresults.html"

    def get_queryset(self):
        sstring = self.request.resolver_match.kwargs["sstring"]
        where = self.request.resolver_match.kwargs["where"]
        if "Question" in where:
            qq = Question.objects.filter(question_text__icontains=sstring)
        else:
            qc = Choice.objects.filter(choice_text__icontains=sstring)
            qq = Question.objects.none()
            for c in qc:
                qq |= Question.objects.filter(pk=c.question_id)
        return qq