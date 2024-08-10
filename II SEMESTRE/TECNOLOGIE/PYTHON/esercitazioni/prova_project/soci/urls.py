from django.urls import path
from . import views

app_name='soci'

urlpatterns = [
        path('persona-create', views.PersonaCreate.as_view(), name='persona-create'),
        ]
