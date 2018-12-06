#include <iostream>
#include "ImageTagger.h"
#include "template_try.h"
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
    i->AddImage(4);
    i->AddImage(5);
    assert(!(i->AddImage(5)));


    i->DeleteImage(1);
    i->DeleteImage(2);
    i->DeleteImage(3);
    i->DeleteImage(4);
    i->DeleteImage(5);
    assert(!(i->DeleteImage(6))); //key doesnt exist
    cout<<endl<<"---supposed to be empty---"<<endl;
    (i->images)->display((i->images)->root, 0);
    cout<<endl<<"--------------------------"<<endl;

    i->AddImage(1);
    i->AddImage(2);
    i->AddImage(3);

    i->AddLabel(1, 1, 1);
    i->AddLabel(1, 1, 2);
    i->AddLabel(1, 2, 2);
    //i->DeleteImage(1, 2, 2);

}