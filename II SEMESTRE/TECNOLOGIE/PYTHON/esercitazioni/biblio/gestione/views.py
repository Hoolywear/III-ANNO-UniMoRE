from django.shortcuts import render
from django.http import HttpResponse
from .models import Libro


# Create your views here.

def lista_libri(request):
    templ = 'gestione/listalibri.html'

    ctx = {
        "title": "Lista di libri",
        "listalibri": Libro.objects.all()
    }

    return render(request, templ, ctx)


MATTONI_THRESHOLD = 300


def mattoni(request):
    templ = 'gestione/listalibri.html'

    lista_filtrata = Libro.objects.all().filter(pagine__gte=MATTONI_THRESHOLD)

    ctx = {
        "title": "Lista di mattoni",
        "listalibri": lista_filtrata
    }

    return render(request, templ, ctx)
