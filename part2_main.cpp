#include <iostream>
#include "ImageTagger.h"
#include <assert.h>

int main(){
    ImageTagger* i = new ImageTagger(5);
    i->AddImage(1);
    assert((i->images)->Size()==1);
    i->DeleteImage(1);
    assert((i->images)->Size()==0);
    i->AddImage(1);
    i->AddImage(2);
    i->AddImage(3);
    (i->images)->display((i->images)->root, 0);

    
}