//
// Created by Hagar on 03/12/2018.
//

#ifndef LIST_STATICEYE_H
#define LIST_STATICEYE_H
#include "tree.h"
#include "list.h"

class value{
public:
    Node none_tagged_ptr[];
    List none_tagged;
    int segments[];

    explicit value (int segments) : none_tagged_ptr(new Node[segments]),
                                    none_tagged(new list()),segments(new int[segments]) {
        for (int i=0; i<segments; i++){
            none_tagged_ptr[i] = ((Node)(none_tagged->Add(i, nullptr)));
            this->segments[i] = -1;
        }
    }
        ~value(){
            delete[](segments);
            delete[](none_tagged_ptr);
            none_tagged->Quit();
        }
};

class ImageTagger{
public:
    Tree images;
    int segments;


    ImageTagger(int segments): images(new tree()),segments(segments){}
    //void *Init(int segments);
    void* AddImage(int imageID);
    void* DeleteImage(int imageID);
    void* AddLabel(int imageID, int segmentID, int label);
    void* GetLabel(int imageID, int segmentID, int *label);
    void* DeleteLabel(int imageID, int segmentID);
    void* GetAllUnLabeledSegments(int imageID, int **segments, int *numOfSegments);
    void* GetAllSegmentsByLabel(int label, int **images, int **segments, int *numOfSegments);
    void Quit();

};

#endif //LIST_STATICEYE_H
