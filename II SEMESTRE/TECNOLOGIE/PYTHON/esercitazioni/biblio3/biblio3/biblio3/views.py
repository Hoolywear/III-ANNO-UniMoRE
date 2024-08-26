from django.shortcuts import render


# Create your views here.

def biblio3_home(request):
    return render(request, template_name="home.html")

