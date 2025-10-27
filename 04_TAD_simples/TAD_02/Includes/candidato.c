#include "candidato.h"
#include <stdio.h>
#include <string.h>

tCandidato CriaCandidato(char *nome, char *partido, char cargo, int id)
{
    return tCandidato();
}

tCandidato LeCandidato()
{
    return tCandidato();
}

int VerificaIdCandidato(tCandidato candidato, int id)
{
    return candidato.id == id;
}

int EhMesmoCandidato(tCandidato candidato1, tCandidato candidato2)
{   
    return !(strcmp(candidato1.nome,candidato2.nome));
}

char ObtemCargo(tCandidato candidato)
{
    return candidato.cargo;
}

tCandidato IncrementaVotoCandidato(tCandidato candidato)
{   
    candidato.votos++;

    return candidato;
}

int ObtemVotos(tCandidato candidato)
{
    return candidato.votos;
}

float CalculaPercentualVotos(tCandidato candidato, int totalVotos)
{   
    float percentualVotos = (candidato.votos*100)/totalVotos;

    return percentualVotos;
}

void ImprimeCandidato(tCandidato candidato, float percentualVotos)
{
}
