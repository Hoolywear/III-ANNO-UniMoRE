from django.urls import path

from .views import *

app_name = "polls"

urlpatterns = [
    path('', IndexViewList.as_view(), name='index'),
    path('<pk>/detail/', DetailQuestion.as_view(), name='detail'),
    path('search/', search, name='search'),
    path('searchresults/<str:sstring>/<str:where>/', SearchResultsList.as_view(), name='searchresults'),
    path('vote/<int:pk>/', vote, name='vote'),
    path('votecasted/<int:pk>/<str:answer>', VoteCastedDetail.as_view(), name='votecasted'),
    path('createquestion/', CreateQuestionView.as_view(), name='createquestion'),
    path('createchoice/', CreateChoiceView.as_view(), name='createchoice'),
]
