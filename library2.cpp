/****************************************************************************/
/*                                                                          */
/* This file contains the interface functions                               */
/* you should use for the wet ex 1                                          */
/*                                                                          */
/****************************************************************************/

/****************************************************************************/
/*                                                                          */
/* File Name : library2.h                                                   */
/*                                                                          */
/****************************************************************************/

#ifndef _234218_WET1_2
#define _234218_WET1_2

#ifdef __cplusplus
extern "C" {
#endif

#include "ImageTagger.h"

/* Return Values
 * ----------------------------------- */
typedef enum {
    SUCCESS = 0,
    FAILURE = -1,
    ALLOCATION_ERROR = -2,
    INVALID_INPUT = -3
} StatusType;


void *Init(int segments){
    try {
        return ((void *) new ImageTagger());
    }catch (bad_alloc& e) {return nullptr;}
}

StatusType AddImage(void *DS, int imageID){
    if(!DS || imageID <= 0) return INVALID_INPUT;
    try {
        if (!((ImageTagger) DS).AddImage(imageID))
            return FAILURE;

        return SUCCESS;
    }catch (bad_alloc& e) { return ALLOCATION_ERROR; }
}

StatusType DeleteImage(void *DS, int imageID){
    if(!DS) return INVALID_INPUT;
    if(!((ImageTagger*)DS)->DeleteImage(imageID)) return FAILURE;
    return SUCCESS;
}

StatusType AddLabel(void *DS, int imageID, int segmentID, int label){
    if(!DS || imageID <= 0 || label <= 0 ||
       segmentID < 0 || segmentID >= ((ImageTagger)DS).segments)
        return INVALID_INPUT;

    try {
        if (!((ImageTagger)DS).AddLabel(imageID, segmentID, label))
            return FAILURE;  // Image doesn't exist

        return SUCCESS;
    }catch (bad_alloc& e) { return ALLOCATION_ERROR; }
}


StatusType GetLabel(void *DS, int imageID, int segmentID, int *label){
    if(!DS || imageID <= 0 || !label ||
       segmentID < 0 || segmentID >= ((ImageTagger)DS).segments)
        return INVALID_INPUT;

    if (!((ImageTagger)DS).GetLabel(imageID,))
        return FAILURE;  // Image doesn't exist

    return SUCCESS;
}


StatusType DeleteLabel(void *DS, int imageID, int segmentID){
    if(!DS || imageID <= 0 ||
       segmentID < 0 || segmentID >= ((ImageTagger)DS).segments)
        return INVALID_INPUT;

    try {
        if (!((ImageTagger)DS).DeleteLabel(imageID, segmentID))
            return FAILURE;  // Image doesn't exist/seg not tagged

        return SUCCESS;
    }catch (bad_alloc& e) { return ALLOCATION_ERROR; }
}

StatusType GetAllSegmentsByLabel(void *DS, int label, int **images, int **segments, int
*numOfSegments){
    if(!DS || !images || !segments || !numOfSegments || label<=0)
        return INVALID_INPUT;
    if(!((ImageTagger*)DS)->GetAllSegmentsByLabel(label,images, segments, numOfSegments))
        return ALLOCATION_ERROR;
    return SUCCESS;
}


void Quit(void** DS){
    if(!DS) return INVALID_INPUT;
    ((ImageTagger*)DS)->Quit();
    DS = nullptr;
}

#ifdef __cplusplus
}
#endif

#endif    /*_234218_WET1_ */