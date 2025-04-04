import datetime

from django.db import models
from django.utils import timezone


class Player(models.Model):
    id = models.AutoField(primary_key=True)
    name = models.CharField(max_length=100)
    action = models.CharField(max_length=10000)
    pourcentage = models.FloatField(default=0.0)
    nbrvictoryF = models.IntegerField(default=0)
    nbrvictoryB = models.IntegerField(default=0)
    nbrdefeatF = models.IntegerField(default=0)
    nbrdefeatB = models.IntegerField(default=0)
    nbrdrawF = models.IntegerField(default=0)
    nbrdrawB = models.IntegerField(default=0)
    numbercase = models.IntegerField(default=0)
    pub_date = models.DateTimeField(auto_now_add=True)

    def __str__(self):
        return self.name

    def was_created_recently(self):
        return self.created_at >= timezone.now() - datetime.timedelta(days=1)
    
    def calcule_victory(self):
        self.pourcentage = (self.nbrvictoryF + self.nbrvictoryB) / (self.nbrvictoryF + self.nbrvictoryB + self.nbrdefeatF + self.nbrdefeatB) * 100
        return self.pourcentage
