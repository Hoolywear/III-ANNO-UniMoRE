from django.shortcuts import render
from django.http import HttpResponse
from .models import Libro

# Create your views here.

def home(request):
    return HttpResponse("Hello world!")

def lista_libri(request):
    templ = 'gestione/listalibri.html'

    ctx = {
        "title" : "Lista di libri",
        "listalibri" : Libro.objects.all()
    }

    return render(request, templ, ctx)