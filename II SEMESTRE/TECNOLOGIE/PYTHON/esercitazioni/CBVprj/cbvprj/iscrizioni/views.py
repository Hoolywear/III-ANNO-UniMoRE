from django.shortcuts import render
from django.views.generic.list import ListView
from .models import *

# Create your views here.

class ListaStudentiView(ListView):
    model = Studente
    template_name = 'iscrizioni/lista_studenti.html'

class ListaInsegnamentiView(ListView):
    model = Insegnamento
    template_name = 'iscrizioni/lista_insegnamenti.html'