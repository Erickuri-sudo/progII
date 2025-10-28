#include "eleicao.h"

tEleicao InicializaEleicao()
{
    tEleicao eleicao;
    eleicao.votosBrancosGovernador = 0;
    eleicao.votosBrancosPresidente = 0;
    eleicao.votosNulosGovernador = 0;
    eleicao.votosNulosPresidente = 0;
    eleicao.totalEleitores = 0;

    int numeroDeCandidatos = 0;

    scanf("%d", &numeroDeCandidatos);

    tCandidato candidatos[numeroDeCandidatos];

    for(int i = 0;i < numeroDeCandidatos;i++){
        candidatos[i] = LeCandidato();
    }

    int idxPresidente = 0;
    int idxGovernador = 0;

    for(int i = 0;i < numeroDeCandidatos;i++){
        if(candidatos[i].cargo = 'P'){
            eleicao.presidentes[idxPresidente] = candidatos[i];
            idxPresidente++;
        }
        else{
            eleicao.governadores[idxGovernador] = candidatos[i];
            idxGovernador++;
        }
    }

    if(idxPresidente > MAX_CANDIDATOS_POR_CARGO){
        eleicao.totalPresidentes = -1;
    }
    else if(idxGovernador > MAX_CANDIDATOS_POR_CARGO){
        eleicao.totalGovernadores = -1;
    }
    else{
        eleicao.totalGovernadores = idxGovernador;
        eleicao.totalPresidentes = idxPresidente;
    }

    return eleicao;
}

tEleicao RealizaEleicao(tEleicao eleicao)
{
    int numeroDeEleitores = 0;

    scanf("%d", &numeroDeEleitores);

    tEleitor eleitores[numeroDeEleitores];

    for(int i = 0;i < numeroDeEleitores; i++){
        eleitores[i] = LeEleitor();
    }

    int eleitorDuplicado = 0;

    for(int i = 0;i < numeroDeEleitores;i++){

        for(int j = i+1;j  < numeroDeEleitores;j++){
            if(EhMesmoEleitor(eleitores[i],eleitores[j])){
                eleicao.totalEleitores = -1;
                eleitorDuplicado = 1;
                break;
            }
        }
        if(eleitorDuplicado){
            break;
        }
    }

    if(eleicao.totalEleitores != -1){
        
        eleicao.totalEleitores = numeroDeEleitores;
        //varre o vetor de eleitores e obtem o voto de presidente da posicao 'i'
    for(int i = 0; i < numeroDeEleitores;i++){
        int votoPresidente = ObtemVotoPresidente(eleitores[i]);

        //se o voto tem valor 0, soma 1 na contagem de votos brancos
        if(votoPresidente == 0){
            eleicao.votosBrancosPresidente++;
        }
        //senao, inicia o processo de encontrar o presidente correspondente ao voto e contabilizar o voto
        else{
            int votoRealizado = 0;
            //varre o vetor dos candidatos e se o id é correspondente, soma 1 ao numero de votos e retorna o candidato com os votos atualizados, além de
            //sinalizar a flag de voto realizado
            for(int j = 0;j < eleicao.totalPresidentes;j++){
                if(VerificaIdCandidato(eleicao.presidentes[j],votoPresidente)){
                    eleicao.presidentes[j] = IncrementaVotoCandidato(eleicao.presidentes[j]);
                    votoRealizado = 1;
                    break;
            }
        }
        //se após o for rodar todas as posicoes nao houve voto realizado, soma o numero de votos nulos para presidente
        if(votoRealizado == 0){
            eleicao.votosNulosPresidente++;
        }

        }
    }

    for(int i = 0; i < numeroDeEleitores;i++){
        int votoGovernador = ObtemVotoGovernador(eleitores[i]);

        //se o voto tem valor 0, soma 1 na contagem de votos brancos
        if(votoGovernador == 0){
            eleicao.votosBrancosGovernador++;
        }
        //senao, inicia o processo de encontrar o presidente correspondente ao voto e contabilizar o voto
        else{
            int votoRealizado = 0;
            //varre o vetor dos candidatos e se o id é correspondente, soma 1 ao numero de votos e retorna o candidato com os votos atualizados, além de
            //sinalizar a flag de voto realizado
            for(int j = 0;j < eleicao.totalGovernadores;j++){
                if(VerificaIdCandidato(eleicao.governadores[j],votoGovernador)){
                    eleicao.governadores[j] = IncrementaVotoCandidato(eleicao.governadores[j]);
                    votoRealizado = 1;
                    break;
            }
        }
        //se após o for rodar todas as posicoes nao houve voto realizado, soma o numero de votos nulos para governador
        if(votoRealizado == 0){
            eleicao.votosNulosGovernador++;
        }

        }
    }
    }

    int maiorNumeroDeVotantes[3];

    for(int i = 0; i < eleicao.totalPresidentes;i++){
        if(eleicao.presidentes[i].votos > eleicao.totalEleitores/2){
            maiorNumeroDeVotantes[i] = eleicao.presidentes[i].id;
        }
    }
    
    return eleicao;
}
