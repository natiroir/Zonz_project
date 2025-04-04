from django.urls import path
# urls.py
from django.conf import settings
from django.conf.urls.static import static
from . import views

urlpatterns = [
    path("", views.index, name="index"),
    path("add/", views.add_player, name="add_player"),
    path("leaderboard/", views.leaderboard, name="leaderboard"),
    path("<int:player_id>/", views.detail, name="detail"),
]

if settings.DEBUG:
    urlpatterns += static(settings.STATIC_URL, document_root=settings.STATIC_ROOT)