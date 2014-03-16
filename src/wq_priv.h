
#ifndef WQ_PRIV_H
#define WQ_PRIV_H


#define WQ_DECL_PRIV(Class) \
    Class* wq_priv_ptr; \
    inline       Class* wq_get_priv()       { return reinterpret_cast<      Class *>(wq_priv_ptr); } \
    inline const Class* wq_get_priv() const { return reinterpret_cast<const Class *>(wq_priv_ptr); } \
    friend class Class;

#define WQ_INIT_PRIV(Class) wq_priv_ptr = new Class;

#define WQ_PRIV(Class) Class * const o = wq_get_priv();


#endif
