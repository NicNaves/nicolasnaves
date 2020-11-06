int list_splice(List *dest, List *source, int pos){
    if(dest == NULL)
        return -1;
    if(source == NULL)
        return -1;
    if(pos < 0)
        return -1;
    if(pos > dest->size)
        return -1;
    DLNode *auxd;
    auxd = dest->begin;
    if(pos == dest->size){
        auxd = dest->end;
        auxd->next = source->begin;
        source->begin->prev = auxd;
 
    }
    if(pos == 1){
        source->end->next = auxd;
        auxd->prev = source->end;
    }
    else{
        int i=0;
        while (i<pos-1){
            auxd = auxd->next;
            i++;
        }
        auxd->next = source->begin;
        source->begin->prev = auxd;
        source->end->next = auxd->next->prev;
        auxd->next->prev = source->end;
    }

    source->begin = NULL;
    source->end = NULL;
    dest->size += source->size;
    source->size = 0;
    return 0;
}

