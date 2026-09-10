#include <stdlib.h>
#include "../include/ocorrencia.h"

void destroi_ocorrencias(Ocorrencia *ocorrencia) {
    if (!ocorrencia) return;

    destroi_ocorrencias(ocorrencia->proximo);
    free(ocorrencia);
}
