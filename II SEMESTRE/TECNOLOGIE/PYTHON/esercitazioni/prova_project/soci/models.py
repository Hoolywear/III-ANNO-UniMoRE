from django.db import models

# Create your models here.

class Persona(models.Model):
    nome = models.CharField(max_length=50)
    cognome = models.CharField(max_length=50)
