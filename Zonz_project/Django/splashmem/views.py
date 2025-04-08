from django.http import HttpResponse
from django.template import loader
from .models import Player
from random import randint

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
import random
def add_player(request):
    if request.method == 'POST':
        form = PlayerForm(request.POST)
        if form.is_valid():
            # Récupère le joueur à partir du formulaire
            player = form.save(commit=False)  # Ne pas encore sauvegarder en base de données
            # Initialiser les autres champs directement en Python
            player.pourcentage = 0  # Exemple de valeur aléatoire entre 0 et 100
            player.nbrvictoryF = 0
            player.nbrvictoryB = 0
            player.nbrdefeatF = 0
            player.nbrdefeatB = 0
            player.nbrdrawF = 0
            player.nbrdrawB = 0
            player.numbercase = 0


            # Parcours tous les jouerus de la bdd 

            otherplayer = Player.objects.all()

            for p in otherplayer:
                victoire, nbrcasep, nbrcaseop = appel_action(player.action, p.action, 0)
                # On va faire un appel à l'action du joueur
                if victoire == 1:
                    player.nbrvictoryF += 1
                    p.nbrdefeatF += 1
                elif victoire == 2:
                    player.nbrdrawF += 1
                    p.nbrdrawF += 1
                elif victoire == 3:
                    player.nbrdefeatF += 1
                    p.nbrvictoryF += 1
                
                p.numbercase += nbrcasep
                player.numbercase += nbrcaseop
                # Match retour

                victoire, nbrcaseop, nbrcasep = appel_action(p.action, player.action, 0)
                if victoire == 1:
                    p.nbrvictoryB += 1
                    player.nbrdefeatB += 1
                elif victoire == 2:
                    p.nbrdrawB += 1
                    player.nbrdrawB += 1
                elif victoire == 3:
                    p.nbrdefeatB += 1
                    player.nbrvictoryB += 1

                p.numbercase += nbrcasep
                player.numbercase += nbrcaseop

                           # Récupère le joueur à partir du formulaire
            player = form.save(commit=False)  # Ne pas encore sauvegarder en base de données
            # Initialiser les autres champs directement en Python
            player.pourcentage = 0  # Exemple de valeur aléatoire entre 0 et 100
            player.nbrvictoryF = 0
            player.nbrvictoryB = 0
            player.nbrdefeatF = 0
            player.nbrdefeatB = 0
            player.nbrdrawF = 0
            player.nbrdrawB = 0
            player.numbercase = 0


            # Parcours tous les jouerus de la bdd 

            otherplayer = Player.objects.all()

            for p in otherplayer:
                victoire, nbrcasep, nbrcaseop = appel_action(player.action, p.action, 0)
                # On va faire un appel à l'action du joueur
                if victoire == 1:
                    player.nbrvictoryF += 1
                    p.nbrdefeatF += 1
                elif victoire == 2:
                    player.nbrdrawF += 1
                    p.nbrdrawF += 1
                elif victoire == 3:
                    player.nbrdefeatF += 1
                    p.nbrvictoryF += 1
                
                p.numbercase += nbrcasep
                player.numbercase += nbrcaseop
                # Match retour

                victoire, nbrcaseop, nbrcasep = appel_action(p.action, player.action, 0)
                if victoire == 1:
                    p.nbrvictoryF += 1
                    player.nbrdefeatF += 1
                elif victoire == 2:
                    p.nbrdrawF += 1
                    player.nbrdrawF += 1
                elif victoire == 3:
                    p.nbrdefeatF += 1
                    player.nbrvictoryF += 1

                p.numbercase += nbrcasep
                player.numbercase += nbrcaseop

                
                victoire, nbrcasep, nbrcaseop = appel_action(player.action, p.action, 1)


                # On va faire un appel à l'action du joueur
                if victoire == 1:
                    player.nbrvictoryB += 1
                    p.nbrdefeatB += 1
                elif victoire == 2:
                    player.nbrdrawB += 1
                    p.nbrdrawB += 1
                elif victoire == 3:
                    player.nbrdefeatB += 1
                    p.nbrvictoryB += 1
                
                p.numbercase += nbrcasep
                player.numbercase += nbrcaseop
                # Match retour

                victoire, nbrcaseop, nbrcasep = appel_action(p.action, player.action, 1)
                if victoire == 1:
                    p.nbrvictoryB += 1
                    player.nbrdefeatB += 1
                elif victoire == 2:
                    p.nbrdrawB += 1
                    player.nbrdrawB += 1
                elif victoire == 3:
                    p.nbrdefeatB += 1
                    player.nbrvictoryB += 1

                p.numbercase += nbrcasep
                player.numbercase += nbrcaseop   

                #Calcule du pourcentage pour l'autre joueur

                if (p.nbrdefeatB + p.nbrdefeatF) != 0:
                    p.pourcentage = (p.nbrvictoryF + p.nbrvictoryB) / (p.nbrdefeatB + p.nbrdefeatF + p.nbrvictoryF + p.nbrvictoryB) * 100
                else:
                    p.pourcentage = 100
                # Sauvegarder l'autre joueur en base de données
                p.save()             


            # Calcule du pourcentage pour le joueur
            if (player.nbrdefeatB + player.nbrdefeatF) != 0:
                player.pourcentage = (player.nbrvictoryF + player.nbrvictoryB) / (player.nbrdefeatB + player.nbrdefeatF + player.nbrvictoryF + player.nbrvictoryB) * 100
            else:
                player.pourcentage = 100
            
            # Sauvegarder le joueur en base de données
            player.save()
 # Redirige vers le leaderboard après l'ajout du joueur
    else:
        form = PlayerForm()  # Crée un formulaire vide

    return render(request, 'splashmem/add_player.html', {'form': form})



def appel_action(np,op,terrain):
    # Fonction pour appeler l'action du joueur
    # np : le joueur qui joue
    # op : le joueur adverse
    # On va faire un appel à l'action du joueur np
    return random.randint(0, 1), random.randint(0, 10000), random.randint(0, 10000)