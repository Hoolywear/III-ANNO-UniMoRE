from django.shortcuts import render, get_object_or_404
from django.http import HttpResponse
from django.utils import timezone

from gestione.models import *


# Create your views here.

def home_view(request):
    return HttpResponse("Hello world!")


def lista_libri(request):
    temp = 'gestione/listalibri.html'

    ctx = {
        "title": "Libri presenti in biblioteca",
        "listalibri": Libro.objects.all(),
    }

    return render(request, temp, ctx)


def prestito(request, titolo, autore):
    temp = 'gestione/presta.html'
    title = "Prestito del libro"
    libro = titolo + " di " + autore
    lc = get_object_or_404(Libro, titolo=titolo, autore=autore).copie.filter(data_prestito=None)

    if lc.count() == 0:
        msg = "Nessuna copia disponibile"
    else:
        try:
            c = get_object_or_404(Copia, pk=lc[0].pk)
            c.data_prestito = timezone.now()
            c.save()
            msg = "Prestito del libro avvenuto con successo! Hai la copia con ID " + str(c.pk)
        except Exception as e:
            msg = "Errore nel prestito! " + str(e)

    ctx = {
        "title": title,
        "libro": libro,
        "message": msg,
    }

    return render(request, temp, ctx)


def restituzione_lista(request, titolo, autore):
    temp = 'gestione/restituisci.html'
    title = "Restituzione del libro"
    libro = titolo + " di " + autore
    lc = get_object_or_404(Libro, titolo=titolo, autore=autore).copie.exclude(data_prestito=None)

    if lc.count() == 0:
        msg = "Nessuna copia da restituire"
        op = ""

    msg = "Lista delle copie in prestito:"
    op = "lista"

    ctx = {
        "title": title,
        "libro": libro,
        "message": msg,
        "op": op,
        "listacopie": lc,
    }

    return render(request, temp, ctx)


def restituzione_final(request, pk):
    temp = 'gestione/restituisci.html'
    title = "Restituzione del libro"
    c = get_object_or_404(Copia, pk=pk)
    libro = c.libro.titolo + " di " + c.libro.autore

    op = "ok"

    if c.scaduto:
        op = "scaduto"

    try:
        c.data_prestito = None
        c.scaduto = False
        c.save()
        msg = f"Copia {str(c.pk)} restituita!"
    except Exception as e:
        msg = "Errore nella restituzione! " + str(e)

    ctx = {
        "title": title,
        "libro": libro,
        "message": msg,
        "op": op,
    }

    return render(request, temp, ctx)
