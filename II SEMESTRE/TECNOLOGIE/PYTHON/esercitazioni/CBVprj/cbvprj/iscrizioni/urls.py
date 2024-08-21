"""
URL configuration for cbvprj project.

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
from django.urls import path
from .views import *

app_name = 'iscrizioni'

urlpatterns = [
    path('listastudenti/', ListaStudentiView.as_view(), name='listastudenti'),
    path('listainsegnamenti/', ListaInsegnamentiView.as_view(), name='listainsegnamenti'),
    path('insegnamentiattivi/', ListaInsegnamentiAttivi.as_view(), name='insegnamentiattivi'),
    path('studentiiscritti/', ListaStudentiIscritti.as_view(), name='studentiiscritti'),
    path('creastudente/', CreateStudenteView.as_view(), name='creastudente'),
    path('creainsegnamento/', CreateInsegnamentoView.as_view(), name='creainsegnamento'),
    path('insegnamento/<pk>/', DetailInsegnamentoView.as_view(), name='insegnamento'),
    path('updateinsegnamento/<pk>/', UpdateInsegnamentoView.as_view(), name='updateinsegnamento'),
    path('cancellastudente/<pk>/', DeleteStudenteView.as_view(), name='cancellastudente'),
    path('cancellainsegnamento/<pk>/', DeleteInsegnamentoView.as_view(), name='cancellainsegnamento'),
]
