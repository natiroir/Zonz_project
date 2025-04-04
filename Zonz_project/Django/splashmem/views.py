from django.http import HttpResponse
from django.template import loader

from .models import Player


def index(request):
    latest_player_list = Player.objects.order_by("-pub_date")[::]
    template = loader.get_template("splashmem/index.html")
    context = {
        "latest_player_list": latest_player_list,
    }
    return HttpResponse(template.render(context, request))

def detail(request, player_id):
    return HttpResponse("You're looking at player %s." % player_id)


def leaderboard(request):
    latest_player_list = Player.objects.order_by("-pourcentage")[::]
    template = loader.get_template("splashmem/leaderboard.html")
    context = {
        "latest_player_list": latest_player_list,
    }
    return HttpResponse(template.render(context, request))

from django.shortcuts import render, redirect
from .forms import PlayerForm

# splashmem/views.py
from django.shortcuts import render, redirect
from .forms import PlayerForm
from .models import Player
from random import randint
def add_player(request):
    if request.method == 'POST':
        form = PlayerForm(request.POST)
        if form.is_valid():
            # Récupère le joueur à partir du formulaire
            player = form.save(commit=False)  # Ne pas encore sauvegarder en base de données

            # Initialiser les autres champs directement en Python
            player.pourcentage = randint(0, 100)  # Exemple de valeur aléatoire entre 0 et 100
            player.nbrvictoryF = 0
            player.nbrvictoryB = 0
            player.nbrdefeatF = 0
            player.nbrdefeatB = 0
            player.nbrdrawF = 0
            player.nbrdrawB = 0
            player.numbercase = 0

            # Sauvegarder le joueur en base de données
            player.save()
 # Redirige vers le leaderboard après l'ajout du joueur
    else:
        form = PlayerForm()  # Crée un formulaire vide

    return render(request, 'splashmem/add_player.html', {'form': form})
