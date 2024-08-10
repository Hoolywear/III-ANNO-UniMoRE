from django.urls import path
from . import views

app_name='soci'

urlpatterns = [
        path('persona-list', views.PersonaList.as_view(), name='persona-list'),
        path('persona-create', views.PersonaCreate.as_view(), name='persona-create'),
        path('persona-delete/<int:pk>', views.PersonaDelete.as_view(), name='persona-delete')
        ]
