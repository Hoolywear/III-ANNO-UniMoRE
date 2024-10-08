from django.shortcuts import render, redirect
from django.urls import reverse, reverse_lazy
from django.views.generic.list import ListView
from django.views.generic.edit import CreateView, UpdateView, DeleteView
from django.views.generic.detail import DetailView
from .models import *


# Create your views here.

class ListaStudentiView(ListView):
    model = Studente
    template_name = 'iscrizioni/lista_studenti.html'


class ListaStudenteBySurname(ListaStudentiView):
    def get_queryset(self):
        arg = self.kwargs['surname']
        qs = self.model.objects.filter(surname__iexact=arg)
        return qs


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


class CreateEntitaView(CreateView):
    template_name = 'iscrizioni/crea_entry.html'
    fields = '__all__'

    def get_context_data(self, **kwargs):
        ctx = super().get_context_data(**kwargs)
        entita = "Studente"
        if self.model == Insegnamento:
            entita = "Insegnamento"
        ctx['entita'] = entita
        return ctx

    def get_success_url(self):
        if self.model == Studente:
            return reverse('iscrizioni:listastudenti')
        else:
            return reverse('iscrizioni:listainsegnamenti')


class CreateStudenteView(CreateEntitaView):
    model = Studente


class CreateInsegnamentoView(CreateEntitaView):
    model = Insegnamento


class DetailInsegnamentoView(DetailView):
    model = Insegnamento
    template_name = 'iscrizioni/insegnamento.html'


class UpdateInsegnamentoView(UpdateView):
    model = Insegnamento
    template_name = "iscrizioni/update_insegnamento.html"
    fields = "__all__"

    def get_success_url(self):
        pk = self.get_context_data()["object"].pk
        return reverse("iscrizioni:insegnamento", kwargs={'pk': pk})


class DeleteEntitaView(DeleteView):
    template_name = 'iscrizioni/cancella_entry.html'

    def get_context_data(self, **kwargs):
        ctx = super().get_context_data(**kwargs)
        entita = "Studente"
        if self.model == Insegnamento:
            entita = "Insegnamento"
        ctx['entita'] = entita
        return ctx

    def get_success_url(self):
        if self.model == Studente:
            return reverse('iscrizioni:listastudenti')
        else:
            return reverse('iscrizioni:listainsegnamenti')


class DeleteStudenteView(DeleteEntitaView):
    model = Studente


class DeleteInsegnamentoView(DeleteEntitaView):
    model = Insegnamento


def cercastudente(request):
    if request.method == 'GET':
        return render(request, template_name='iscrizioni/cerca_studente.html')
    else:
        if len(request.POST['name']) < 1:
            nome = 'null'
        else:
            nome = request.POST['name']

        if len(request.POST['surname']) < 1:
            cognome = 'null'
        else:
            cognome = request.POST['surname']

        return redirect("iscrizioni:studentecercato", name=nome, surname=cognome)


class SearchStudenteView(ListView):
    model = Studente
    template_name = 'iscrizioni/lista_studente_cercato.html'

    def get_queryset(self):

        try:
            arg = self.kwargs['name']
            qs_name = self.model.objects.filter(name__iexact=arg)
        except:
            qs_name = self.model.objects.none()

        try:
            arg = self.kwargs['surname']
            qs_surname = self.model.objects.filter(surname__iexact=arg)
        except:
            qs_surname = self.model.objects.none()

        return qs_name | qs_surname

    def get_context_data(self, **kwargs):
        ctx = super().get_context_data(**kwargs)
        ctx['titolo'] = 'Studenti e loro insegnamenti'
        ls = set()
        for s in self.get_queryset():
            for i in Insegnamento.objects.all():
                if s in i.studenti.all():
                    ls.add(i)

        ctx['set_ins'] = ls

        return ctx
