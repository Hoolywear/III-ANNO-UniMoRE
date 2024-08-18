from django.shortcuts import render
from django.http import HttpResponse
from .models import Libro
from django.utils import timezone


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


def autore_path(request, autore):
    templ = 'gestione/listalibri.html'

    aut = autore

    filtered_list = Libro.objects.all().filter(autore__icontains=aut)

    ctx = {
        "title": f"Libri di {aut}",
        "listalibri": filtered_list
    }
    return render(request, templ, ctx)


def crea_libro(request):
    message = ""

    if "autore" in request.GET and "titolo" in request.GET:
        aut = request.GET["autore"]
        tit = request.GET["titolo"]
        pag = 100

        try:
            pag = int(request.GET["pagine"])
        except:
            message = " Pagine non valide. Inserite pagine di default."

        l = Libro()
        l.autore = aut
        l.titolo = tit
        l.pagine = pag
        l.data_prestito = timezone.now()

        try:
            l.save()
            message = "Creazione libro riuscita!" + message
        except Exception as e:
            message = "Errore nella creazione del libro " + str(e)

    return render(request, template_name="gestione/crealibro.html",
                  context={"title": "Crea Autore", "message": message})
