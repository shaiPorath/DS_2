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

StatusType AddLabel(void *DS, int imageID, int segmentID, int label);


StatusType GetLabel(void *DS, int imageID, int segmentID, int *label);


StatusType DeleteLabel(void *DS, int imageID, int segmentID);


StatusType GetAllUnLabeledSegments(void *DS, int imageID, int **segments, int *numOfSegments);


StatusType GetAllSegmentsByLabel(void *DS, int label, int **images, int **segments, int *numOfSegments);


void Quit(void** DS);

#ifdef __cplusplus
}
#endif

#endif    /*_234218_WET1_ */