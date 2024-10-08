# Generated by Django 5.1 on 2024-08-20 10:36

from django.db import migrations, models


class Migration(migrations.Migration):

    initial = True

    dependencies = [
    ]

    operations = [
        migrations.CreateModel(
            name='Studente',
            fields=[
                ('id', models.BigAutoField(auto_created=True, primary_key=True, serialize=False, verbose_name='ID')),
                ('name', models.CharField(max_length=50)),
                ('surname', models.CharField(max_length=50)),
            ],
            options={
                'verbose_name_plural': 'Studenti',
            },
        ),
        migrations.CreateModel(
            name='Insegnamento',
            fields=[
                ('id', models.BigAutoField(auto_created=True, primary_key=True, serialize=False, verbose_name='ID')),
                ('titolo', models.CharField(max_length=50)),
                ('studenti', models.ManyToManyField(default=None, to='iscrizioni.studente')),
            ],
            options={
                'verbose_name_plural': 'Insegnamenti',
            },
        ),
    ]
