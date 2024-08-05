from django.http import HttpResponse

def home(request):
  return HttpResponse("Hello world! Questa è la home page.")
