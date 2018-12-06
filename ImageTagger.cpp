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
    delete((images->Find_value(imageID)));
    if (!images->Delete(imageID)) return nullptr;
    return this;
}

void* ImageTagger::AddLabel(int imageID, int segmentID, int label){

}
/*
void* ImageTagger::GetLabel(int imageID, int segmentID, int *label);

void* ImageTagger::DeleteLabel(int imageID, int segmentID);

void* ImageTagger::GetAllUnLabeledSegments(int imageID, int **segments, int
*numOfSegments);

void* ImageTagger::GetAllSegmentsByLabel(int label, int **images, int **segments, int
*numOfSegments);

void ImageTagger::Quit();*/