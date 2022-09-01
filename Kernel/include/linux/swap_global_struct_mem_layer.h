
#ifndef __LINUX_SWAP_SWAP_GLOBAL_STRUCT_MEM_LAYER_H
#define __LINUX_SWAP_SWAP_GLOBAL_STRUCT_MEM_LAYER_H

#include <linux/swap_global_struct.h>


//
// Global variables 
//

// defined in extended_syscall.c
extern void *user_kernel_shared_data;


// [TODO] Actually, we can store the present of not information
// into the page_stat and let the runtime query this information
// In this case, the epoch is useless?
struct epoch_struct{
  unsigned int epoch;   // the first 32 bits for epoch recording
  unsigned int page_stat[COVERED_MEM_LENGTH];  // the epoch value for each page
};



//
// Functions
//


enum check_mode{
  CHECK_FLUSH_MOD   = 1,
  CHECK_SWAP_SYSTEM = 2,
  DEFAULT,
};

void print_page_flags(struct page *page, enum check_mode print_mode, const char* message);
void print_virt_addr_of_page(struct page *page, const char* message);
void print_swap_info_struct(swp_entry_t entry, const char* message);

swp_entry_t walk_page_table_for_swap_entry(struct mm_struct * mm, unsigned long user_virt_addr );  // ONLY walk the page table of user process. Return the pte copied pte value or 0 for empty page table.

// declared as a funtion pointer??
//extern void (*mmap_user_kernel_shared_mem)(unsigned long, unsigned long);


#endif // __LINUX_SWAP_SWAP_GLOBAL_STRUCT_MEM_LAYER_H