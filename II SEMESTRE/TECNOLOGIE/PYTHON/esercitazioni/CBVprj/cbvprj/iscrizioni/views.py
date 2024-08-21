from django.shortcuts import render
from django.urls import reverse, reverse_lazy
from django.views.generic.list import ListView
from django.views.generic.edit import CreateView, UpdateView, DeleteView
from .models import *


# Create your views here.

class ListaStudentiView(ListView):
    model = Studente
    template_name = 'iscrizioni/lista_studenti.html'


class ListaInsegnamentiView(ListView):
    model = Insegnamento
    template_name = 'iscrizioni/lista_insegnamenti.html'


class ListaInsegnamentiAttivi(ListView):
    model = Insegnamento
    template_name = 'iscrizioni/insegnamenti_attivi.html'

    def get_queryset(self):
        return self.model.objects.exclude(studenti__isnull=True)

    def get_context_data(self, **kwargs):
        context = super().get_context_data(**kwargs)
        context['titolo'] = 'Insegnamenti attivi'
        return context


class ListaStudentiIscritti(ListView):
    model = Studente
    template_name = "iscrizioni/studenti_iscritti.html"

    def get_model_name(self):
        return self.model._meta.verbose_name_plural

    def get_context_data(self, **kwargs):
        ctx = super().get_context_data(**kwargs)
        ctx["titolo"] = "Lista studenti con iscrizioni"
        return ctx

    def get_totale_iscrizioni(self):
        count = 0
        for i in Insegnamento.objects.all():
            count += i.studenti.all().count()
        return count

class CreateStudenteView(CreateView):
    model = Studente
    template_name = 'iscrizioni/crea_studente.html'
    fields = '__all__'
    success_url = reverse_lazy('iscrizioni:listastudenti')


