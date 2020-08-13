#pragma once

#ifdef  __cplusplus
extern "C" {
#endif //  __cplusplus


	typedef struct list {
		int data;
		struct list* next;
	}LIST;

	LIST* list_add(LIST* p, int val);
	LIST* list_delete(LIST* p);
	void list_delete_next(LIST* p);
	void delete_list_all(LIST*);

	int list_get_data(const LIST* p);
	int list_length(const LIST* p);

#ifdef  __cplusplus
}
#endif //  __cplusplus
