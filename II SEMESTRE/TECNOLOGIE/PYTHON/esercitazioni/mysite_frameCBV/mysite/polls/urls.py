from django.urls import path

from .views import *

app_name = "polls"

urlpatterns = [
    path('', IndexViewList.as_view(), name='index'),
    path('<pk>/detail/', DetailQuestion.as_view(), name='detail'),

]
