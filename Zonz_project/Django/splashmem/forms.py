# splashmem/forms.py
from django import forms
from .models import Player  # Assurez-vous d'importer votre modèle Player

class PlayerForm(forms.ModelForm):
    class Meta:
        model = Player
        fields = ['name', 'action']  # Liste des champs de ton modèle