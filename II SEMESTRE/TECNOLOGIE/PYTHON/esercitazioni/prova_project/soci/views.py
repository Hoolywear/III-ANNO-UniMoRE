from django.shortcuts import render
from django.urls import reverse_lazy
from django.views.generic.edit import CreateView
from .models import *

# Create your views here.

class PersonaCreate(CreateView):
    model = Persona
    fields = ('nome', 'cognome', 'ruolo')
    template_name = 'soci/persona_create.html'
    success_url = reverse_lazy('soci:persona-list')
  
