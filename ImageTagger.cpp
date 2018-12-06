//
// Created by Hagar on 03/12/2018.
//
#include "ImageTagger.h"


void* ImageTagger::AddImage(int imageID){
    if (imageID <= 0) return nullptr;

    if (images->Find(imageID))  //image already in tree
        return nullptr;

    value* new_value = new value (this->segments);

    if( !(images->Add(imageID, new_value))) return nullptr;
    return this;
}

void* ImageTagger::DeleteImage(int imageID){
    delete((value*)(images->Find(imageID)));
    if (!images->Delete(imageID)) return nullptr;
    return this;
}

void* ImageTagger::AddLabel(int imageID, int segmentID, int label){
    if (imageID <= 0 || label <= 0 ||
        segmentID < 0 || segmentID >= this->segments) return nullptr;

    value* val = ((value*)((images->Find(imageID))));
    if (!val)
        return nullptr; // Image doesn't exist

    if (((val->segments)[segmentID-1]) != -1)
        return nullptr; //segment was already labeled

    //start labeling the segment
    void* list_ptr = (val->none_tagged_ptr)[segmentID-1];

    (val->none_tagged)->DeleteByPointer(list_ptr);  //delete node from list

    (val->none_tagged_ptr)[segmentID-1] = nullptr;    //update array to null
    ((val->segments)[segmentID-1]) = segmentID;

    return val;
}


void* ImageTagger::GetLabel(int imageID, int segmentID, int *label){
    if (imageID <= 0 || !label ||
        segmentID < 0 || segmentID >= this->segments) return nullptr;

    value* val = ((value*)((images->Find(imageID))));
    if (!val)
        return nullptr; // Image doesn't exist


    if (((val->none_tagged_ptr)[segmentID-1])){ //if not null, seg was not labeled
        label = nullptr;
        return label;
    }

    //segment was already labeled
    label = &val->segments[segmentID-1];

    return label;
}


void* ImageTagger::DeleteLabel(int imageID, int segmentID){
    if (imageID <= 0 || segmentID < 0 || segmentID >= this->segments)
        return nullptr;

    value* val = ((value*)((images->Find(imageID))));

    if (!val || ((val->none_tagged_ptr)[segmentID-1]))
        //Image doesn't exist || if not null, seg was not labeled
        return nullptr;

    // Image exists and seg was labeled
    val->segments[segmentID-1] = -1;
    (val->none_tagged_ptr[segmentID-1]) =
            (Node)(val->none_tagged)->Add(segmentID, nullptr);

    return this;
}

void* ImageTagger::GetAllSegmentsByLabel(int label, int **images, int **segments, int
*numOfSegments){
    if(!numOfSegments || !images || !segments) return nullptr;
    *numOfSegments = 0;

    int* keys = (this->images)->key_arr();
    value** values = (value**)(this->images)->val_arr();
    int i, i_output=0, tree_size = (this->images)->Size();

    for (i=0; i<tree_size; i++){
        *numOfSegments += (values[i])->count_seg_by_label(label, this->segments);
    }
    if(*numOfSegments == 0){
        images = nullptr;
        segments = nullptr;
        return this;
    }

    *images = (int*)malloc((*numOfSegments)* sizeof(int));
    if (!*images)
        return nullptr;
    *segments = (int*)malloc((*numOfSegments)* sizeof(int));
    if (!*segments)
        return nullptr;

    for (i=0; i<tree_size; i++){
        for ( int j=0; j<(this->segments); j++){
            if( (values[i])->segments[j] == label){
                *images[i_output] = keys[i];
                *segments[i_output++] = j+1;
            }
        }

    }

    delete[](keys);
    delete[](values);
    return this;
}

void* ImageTagger::GetAllUnLabeledSegments(int imageID, int **segments, int *numOfSegments){
    if (!segments || !numOfSegments) return nullptr;

    value* val = ((value*)(this->images)->Find(imageID));

    if (!val) return nullptr;

    *segments = (val->none_tagged)->key_arr();
    if (!(*segments)) return nullptr;

    return segments;
}

void ImageTagger::Quit(){
    value** val_arr = (value**)((this->images)->val_arr());
    int size = images->Size();
    for(int i=0; i<size; i++){
        delete(val_arr[i]);
    }
    images->Quit();
    delete[](val_arr);
    delete(this);
}