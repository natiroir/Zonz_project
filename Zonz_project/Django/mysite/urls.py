from django.contrib import admin
from django.urls import include, path

urlpatterns = [
    path("splashmem/", include("splashmem.urls")),
    path("admin/", admin.site.urls),
]      