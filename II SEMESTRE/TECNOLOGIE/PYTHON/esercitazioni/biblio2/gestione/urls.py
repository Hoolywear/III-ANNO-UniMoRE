"""
URL configuration for biblio2 project.

The `urlpatterns` list routes URLs to views. For more information please see:
    https://docs.djangoproject.com/en/5.1/topics/http/urls/
Examples:
Function views
    1. Add an import:  from my_app import views
    2. Add a URL to urlpatterns:  path('', views.home, name='home')
Class-based views
    1. Add an import:  from other_app.views import Home
    2. Add a URL to urlpatterns:  path('', Home.as_view(), name='home')
Including another URLconf
    1. Import the include() function: from django.urls import include, path
    2. Add a URL to urlpatterns:  path('blog/', include('blog.urls'))
"""
from django.contrib import admin
from django.urls import path
from gestione.views import *

app_name = 'gestione'

urlpatterns = [
    path('', home_view, name='homeview'),
    path('listalibri/', lista_libri, name='listalibri'),
    path('prestito/<str:titolo>/<str:autore>', prestito, name='prestito'),
    path('restituzione/<str:titolo>/<str:autore>', restituzione_lista, name='restituzione_lista'),
    path('restituzione/<int:pk>', restituzione_final, name='restituzione_final'),
]
