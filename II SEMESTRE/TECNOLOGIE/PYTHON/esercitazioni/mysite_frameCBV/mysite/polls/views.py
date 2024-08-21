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
