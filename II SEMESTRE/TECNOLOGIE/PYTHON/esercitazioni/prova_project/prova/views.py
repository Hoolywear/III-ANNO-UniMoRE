from django.http import HttpResponse
from datetime import datetime
from django.shortcuts import render

import logging
logger = logging.getLogger(__name__)

def home(request):
    return HttpResponse("Hello world! Questa è la home page.")

def home_page(request):
    response = f"Benvenuto nella homepage, {str(request.user)}"
  
    if not request.user.is_authenticated:
        logger.warning(f'{str(request.user)} non è autenticato!')

    return HttpResponse(response)
    
def elenca_params(request):
    response=''
    for k in request.GET:
        response += request.GET[k] + ' '

    return HttpResponse(response)

def welcome_path(request,nome,eta):
    return HttpResponse(f'Richiesta da {nome} che ha {str(eta)} anni.')

def hello_template(request):
    ctx = {
            "title" : "Hello Template",
            "lista" : [ datetime.now(), datetime.today().strftime('%A'), datetime.today().strftime('%B') ]
            }

    return render(request, template_name="baseext.html", context=ctx)
