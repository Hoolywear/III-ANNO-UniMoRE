from django.shortcuts import render
from django.urls import reverse_lazy
from django.views.generic.list import ListView
from django.views.generic.edit import CreateView, DeleteView
from .models import *

# Create your views here.

class PersonaList(ListView):
    model = Persona
    template_name = "soci/persona_list.html"

class PersonaCreate(CreateView):
    model = Persona
    fields = ('nome', 'cognome', 'ruolo')
    template_name = 'soci/persona_create.html'
    success_url = reverse_lazy('soci:persona-list')
  
class PersonaDelete(DeleteView):
    model = Persona
    template_name = 'soci/persona_delete.html'
    success_url = reverse_lazy('soci:persona-list')
