#include <stdio.h>
#define MAX_PAGE_FRAMES 10
#define MAX_PAGE_REFERENCES 20
int page_frames[MAX_PAGE_FRAMES];
int page_reference_string[MAX_PAGE_REFERENCES] = {1, 2, 3, 4, 2, 1, 5, 6, 2, 1, 2, 3, 7, 6, 3, 2, 1, 2, 3, 6};
int page_faults = 0;
int find_page_fault(int page_reference) {
    int i;
    for (i = 0; i < MAX_PAGE_FRAMES; i++) {
        if (page_frames[i] == page_reference) {
            return 0;
        }
    }
    return 1;
}
int main() {
    int i, j, current_page, next_page;
    for (i = 0; i < MAX_PAGE_FRAMES; i++) {
        page_frames[i] = -1;
    }
    for (i = 0; i < MAX_PAGE_REFERENCES; i++) {
        current_page = page_reference_string[i];
        if (find_page_fault(current_page)) {
            page_faults++;
            for (j = 0; j < MAX_PAGE_FRAMES - 1; j++) {
                page_frames[j] = page_frames[j + 1];
            }
            page_frames[MAX_PAGE_FRAMES - 1] = current_page;
        }
        printf("Page frames: ");
        for (j = 0; j < MAX_PAGE_FRAMES; j++) {
            printf("%d ", page_frames[j]);
        }
        printf("\n");
    }
    printf("Total page faults: %d\n", page_faults);
    return 0;
}

