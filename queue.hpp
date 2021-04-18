#pragma once

namespace strukdat
{

  namespace priority_queue
  {

    /**
 * @brief Implementasi struct untuk elemen, harus ada isi dan prioritas elemen.
 */
    template <typename T>
    struct Element
    {
      T data;
      int priority;
      Element *next;
    };

    template <typename T>
    using ElementPtr = Element<T> *;

    /**
 * @brief implemetasi struct untuk queue.
 */
    template <typename T>
    struct Queue
    {
      ElementPtr<T> head;
      ElementPtr<T> tail;
    };

    /**
 * @brief membuat queue baru
 *
 * @return  queue kosong
 */
    template <typename T>
    Queue<T> new_queue()
    {
      Queue<T> newQueue;
      newQueue.head = nullptr;
      newQueue.tail = nullptr;
      return newQueue;
    }

    /**
 * @brief memasukan data sesuai priority elemen.
 *
 * @param q         queue yang dipakai.
 * @param value     isi dari elemen.
 * @param priority  prioritas elemen yang menentukan urutan.
 */
    template <typename T>
    void enqueue(Queue<T> &q, const T &value, int priority)
    {
      ElementPtr<T> new_element = new Element<T>;
      ElementPtr<T> pNext = q.head, pPrev = nullptr;
      new_element->data = value;
      new_element->priority = priority;
      if (q.head == nullptr && q.tail == nullptr)
      {
        q.head = new_element;
        q.tail = new_element;
      }
      else
      {
        while (new_element->priority <= pNext->priority && pNext->next != nullptr)
        {
          pPrev = pNext;
          pNext = pNext->next;
        }
        if (pNext == q.head)
        {
          new_element->next = pNext;
          q.head = new_element;
        }
        else if (pNext == q.tail)
        {
          pNext->next = new_element;
          q.tail = new_element;
        }
        else
        {
          pPrev->next = new_element;
          new_element->next = pNext;
        }
      }
    }

    /**
 * @brief mengembalikan isi dari elemen head.
 *
 * @param q   queue yang dipakai.
 * @return    isi dari elemen head.
 */
    template <typename T>
    T top(const Queue<T> &q)
    {
      return q.head->data;
    }

    /**
 * @brief menghapus elemen head queue (First in first out).
 *
 * @param q   queue yang dipakai.
 */
    template <typename T>
    void dequeue(Queue<T> &q)
    {
      ElementPtr<T> pDelete;
      if (!q.head)
      {
        pDelete = nullptr;
      }
      else if (q.head->next == nullptr)
      {
        pDelete = q.head;
        q.head = q.tail = nullptr;
        delete pDelete;
      }
      else
      {
        pDelete = q.head;
        q.head = q.head->next;
        pDelete->next = nullptr;
        delete pDelete;
      }
    }

  } // namespace priority_queue

} // namespace strukdat
