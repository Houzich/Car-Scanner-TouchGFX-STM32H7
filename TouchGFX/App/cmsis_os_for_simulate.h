


#ifndef QUEUE_H
#define QUEUE_H
#ifdef __cplusplus
extern "C" {
#endif
/**
 * Type by which queues are referenced.  For example, a call to xQueueCreate()
 * returns an QueueHandle_t variable that can then be used as a parameter to
 * xQueueSend(), xQueueReceive(), etc.
 */
struct QueueDefinition; /* Using old naming convention so as not to break kernel aware debuggers. */
typedef struct QueueDefinition* QueueHandle_t;

#ifdef __cplusplus
}
#endif

#endif /* QUEUE_H */




#ifndef _CMSIS_OS_H
#define _CMSIS_OS_H
 /// \note MUST REMAIN UNCHANGED: \b osCMSIS identifies the CMSIS-RTOS API version.
#define osCMSIS           0x10002      ///< API version (main [31:16] .sub [15:0])

/// \note CAN BE CHANGED: \b osCMSIS_KERNEL identifies the underlying RTOS kernel and version number.
#define osCMSIS_KERNEL    0x10000	   ///< RTOS identification and version (main [31:16] .sub [15:0])

/// \note MUST REMAIN UNCHANGED: \b osKernelSystemId shall be consistent in every CMSIS-RTOS.
#define osKernelSystemId "KERNEL V1.00"   ///< RTOS identification string

/// \note MUST REMAIN UNCHANGED: \b osFeature_xxx shall be consistent in every CMSIS-RTOS.
#define osFeature_MainThread   1       ///< main thread      1=main can be thread, 0=not available
#define osFeature_Pool         1       ///< Memory Pools:    1=available, 0=not available
#define osFeature_MailQ        1       ///< Mail Queues:     1=available, 0=not available
#define osFeature_MessageQ     1       ///< Message Queues:  1=available, 0=not available
#define osFeature_Signals      8       ///< maximum number of Signal Flags available per thread
#define osFeature_Semaphore    1      ///< osFeature_Semaphore function: 1=available, 0=not available
#define osFeature_Wait         0       ///< osWait function: 1=available, 0=not available
#define osFeature_SysTick      1       ///< osKernelSysTick functions: 1=available, 0=not available

#ifdef  __cplusplus
extern "C"
{
#endif


	// ==== Enumeration, structures, defines ====

	/// Priority used for thread control.
	/// \note MUST REMAIN UNCHANGED: \b osPriority shall be consistent in every CMSIS-RTOS.
	typedef enum {
		osPriorityIdle = -3,          ///< priority: idle (lowest)
		osPriorityLow = -2,          ///< priority: low
		osPriorityBelowNormal = -1,          ///< priority: below normal
		osPriorityNormal = 0,          ///< priority: normal (default)
		osPriorityAboveNormal = +1,          ///< priority: above normal
		osPriorityHigh = +2,          ///< priority: high
		osPriorityRealtime = +3,          ///< priority: realtime (highest)
		osPriorityError = 0x84        ///< system cannot determine priority or thread has illegal priority
	} osPriority;

	/// Timeout value.
	/// \note MUST REMAIN UNCHANGED: \b osWaitForever shall be consistent in every CMSIS-RTOS.
#define osWaitForever     0xFFFFFFFF     ///< wait forever timeout value

/// Status code values returned by CMSIS-RTOS functions.
/// \note MUST REMAIN UNCHANGED: \b osStatus shall be consistent in every CMSIS-RTOS.
	typedef enum {
		osOK = 0,       ///< function completed; no error or event occurred.
		osEventSignal = 0x08,       ///< function completed; signal event occurred.
		osEventMessage = 0x10,       ///< function completed; message event occurred.
		osEventMail = 0x20,       ///< function completed; mail event occurred.
		osEventTimeout = 0x40,       ///< function completed; timeout occurred.
		osErrorParameter = 0x80,       ///< parameter error: a mandatory parameter was missing or specified an incorrect object.
		osErrorResource = 0x81,       ///< resource not available: a specified resource was not available.
		osErrorTimeoutResource = 0xC1,       ///< resource not available within given time: a specified resource was not available within the timeout period.
		osErrorISR = 0x82,       ///< not allowed in ISR context: the function cannot be called from interrupt service routines.
		osErrorISRRecursive = 0x83,       ///< function called multiple times from ISR with same object.
		osErrorPriority = 0x84,       ///< system cannot determine priority or thread has illegal priority.
		osErrorNoMemory = 0x85,       ///< system is out of memory: it was impossible to allocate or reserve memory for the operation.
		osErrorValue = 0x86,       ///< value of a parameter is out of range.
		osErrorOS = 0xFF,       ///< unspecified RTOS error: run-time error but no other error message fits.
		os_status_reserved = 0x7FFFFFFF  ///< prevent from enum down-size compiler optimization.
	} osStatus;

#if ( INCLUDE_eTaskGetState == 1 )
	/* Thread state returned by osThreadGetState */
	typedef enum {
		osThreadRunning = 0x0,	      /* A thread is querying the state of itself, so must be running. */
		osThreadReady = 0x1,			        /* The thread being queried is in a read or pending ready list. */
		osThreadBlocked = 0x2,		        /* The thread being queried is in the Blocked state. */
		osThreadSuspended = 0x3,	      /* The thread being queried is in the Suspended state, or is in the Blocked state with an infinite time out. */
		osThreadDeleted = 0x4,		          /* The thread being queried has been deleted, but its TCB has not yet been freed. */
		osThreadError = 0x7FFFFFFF
	} osThreadState;
#endif /* INCLUDE_eTaskGetState */

	/// Timer type value for the timer definition.
	/// \note MUST REMAIN UNCHANGED: \b os_timer_type shall be consistent in every CMSIS-RTOS.
	typedef enum {
		osTimerOnce = 0,       ///< one-shot timer
		osTimerPeriodic = 1        ///< repeating timer
	} os_timer_type;

	/// Entry point of a thread.
	/// \note MUST REMAIN UNCHANGED: \b os_pthread shall be consistent in every CMSIS-RTOS.
	typedef void (*os_pthread) (void const* argument);

	/// Entry point of a timer call back function.
	/// \note MUST REMAIN UNCHANGED: \b os_ptimer shall be consistent in every CMSIS-RTOS.
	typedef void (*os_ptimer) (void const* argument);

	// >>> the following data type definitions may shall adapted towards a specific RTOS

	///// Thread ID identifies the thread (pointer to a thread control block).
	///// \note CAN BE CHANGED: \b os_thread_cb is implementation specific in every CMSIS-RTOS.
	//typedef TaskHandle_t osThreadId;

	///// Timer ID identifies the timer (pointer to a timer control block).
	///// \note CAN BE CHANGED: \b os_timer_cb is implementation specific in every CMSIS-RTOS.
	//typedef TimerHandle_t osTimerId;

	///// Mutex ID identifies the mutex (pointer to a mutex control block).
	///// \note CAN BE CHANGED: \b os_mutex_cb is implementation specific in every CMSIS-RTOS.
	//typedef SemaphoreHandle_t osMutexId;

	///// Semaphore ID identifies the semaphore (pointer to a semaphore control block).
	///// \note CAN BE CHANGED: \b os_semaphore_cb is implementation specific in every CMSIS-RTOS.
	//typedef SemaphoreHandle_t osSemaphoreId;

	///// Pool ID identifies the memory pool (pointer to a memory pool control block).
	///// \note CAN BE CHANGED: \b os_pool_cb is implementation specific in every CMSIS-RTOS.
	//typedef struct os_pool_cb* osPoolId;

	/// Message ID identifies the message queue (pointer to a message queue control block).
	/// \note CAN BE CHANGED: \b os_messageQ_cb is implementation specific in every CMSIS-RTOS.
	typedef QueueHandle_t osMessageQId;

	/// Mail ID identifies the mail queue (pointer to a mail queue control block).
	/// \note CAN BE CHANGED: \b os_mailQ_cb is implementation specific in every CMSIS-RTOS.
	typedef struct os_mailQ_cb* osMailQId;


#if( configSUPPORT_STATIC_ALLOCATION == 1 )

	typedef StaticTask_t               osStaticThreadDef_t;
	typedef StaticTimer_t              osStaticTimerDef_t;
	typedef StaticSemaphore_t          osStaticMutexDef_t;
	typedef StaticSemaphore_t          osStaticSemaphoreDef_t;
	typedef StaticQueue_t              osStaticMessageQDef_t;

#endif




	/// Thread Definition structure contains startup information of a thread.
	/// \note CAN BE CHANGED: \b os_thread_def is implementation specific in every CMSIS-RTOS.
	typedef struct os_thread_def {
		char* name;        ///< Thread name 
		os_pthread             pthread;      ///< start address of thread function
		osPriority             tpriority;    ///< initial thread priority
		uint32_t               instances;    ///< maximum number of instances of that thread function
		uint32_t               stacksize;    ///< stack size requirements in bytes; 0 is default stack size
#if( configSUPPORT_STATIC_ALLOCATION == 1 )
		uint32_t* buffer;      ///< stack buffer for static allocation; NULL for dynamic allocation
		osStaticThreadDef_t* controlblock;     ///< control block to hold thread's data for static allocation; NULL for dynamic allocation
#endif
	} osThreadDef_t;

	/// Timer Definition structure contains timer parameters.
	/// \note CAN BE CHANGED: \b os_timer_def is implementation specific in every CMSIS-RTOS.
	typedef struct os_timer_def {
		os_ptimer                 ptimer;    ///< start address of a timer function
#if( configSUPPORT_STATIC_ALLOCATION == 1 )
		osStaticTimerDef_t* controlblock;      ///< control block to hold timer's data for static allocation; NULL for dynamic allocation
#endif
	} osTimerDef_t;

	/// Mutex Definition structure contains setup information for a mutex.
	/// \note CAN BE CHANGED: \b os_mutex_def is implementation specific in every CMSIS-RTOS.
	typedef struct os_mutex_def {
		uint32_t                   dummy;    ///< dummy value.
#if( configSUPPORT_STATIC_ALLOCATION == 1 )
		osStaticMutexDef_t* controlblock;      ///< control block for static allocation; NULL for dynamic allocation
#endif
	} osMutexDef_t;

	/// Semaphore Definition structure contains setup information for a semaphore.
	/// \note CAN BE CHANGED: \b os_semaphore_def is implementation specific in every CMSIS-RTOS.
	typedef struct os_semaphore_def {
		uint32_t                   dummy;    ///< dummy value.
#if( configSUPPORT_STATIC_ALLOCATION == 1 )
		osStaticSemaphoreDef_t* controlblock;      ///< control block for static allocation; NULL for dynamic allocation
#endif
	} osSemaphoreDef_t;

	/// Definition structure for memory block allocation.
	/// \note CAN BE CHANGED: \b os_pool_def is implementation specific in every CMSIS-RTOS.
	typedef struct os_pool_def {
		uint32_t                 pool_sz;    ///< number of items (elements) in the pool
		uint32_t                 item_sz;    ///< size of an item
		void* pool;    ///< pointer to memory for pool
	} osPoolDef_t;

	/// Definition structure for message queue.
	/// \note CAN BE CHANGED: \b os_messageQ_def is implementation specific in every CMSIS-RTOS.
	typedef struct os_messageQ_def {
		uint32_t                queue_sz;    ///< number of elements in the queue
		uint32_t                item_sz;    ///< size of an item
#if( configSUPPORT_STATIC_ALLOCATION == 1 )
		uint8_t* buffer;      ///< buffer for static allocation; NULL for dynamic allocation
		osStaticMessageQDef_t* controlblock;     ///< control block to hold queue's data for static allocation; NULL for dynamic allocation
#endif
  //void                       *pool;    ///< memory array for messages
	} osMessageQDef_t;

	/// Definition structure for mail queue.
	/// \note CAN BE CHANGED: \b os_mailQ_def is implementation specific in every CMSIS-RTOS.
	typedef struct os_mailQ_def {
		uint32_t                queue_sz;    ///< number of elements in the queue
		uint32_t                 item_sz;    ///< size of an item
		struct os_mailQ_cb** cb;
	} osMailQDef_t;

	/// Event structure contains detailed information about an event.
	/// \note MUST REMAIN UNCHANGED: \b os_event shall be consistent in every CMSIS-RTOS.
	///       However the struct may be extended at the end.
	typedef struct {
		osStatus                 status;     ///< status code: event or error information
		union {
			uint32_t                    v;     ///< message as 32-bit value
			void* p;     ///< message or mail as void pointer
			int32_t               signals;     ///< signal flags
		} value;                             ///< event value
		union {
			osMailQId             mail_id;     ///< mail id obtained by \ref osMailCreate
			osMessageQId       message_id;     ///< message id obtained by \ref osMessageCreate
		} def;                               ///< event definition
	} osEvent;


#ifdef  __cplusplus
}
#endif

#endif  // _CMSIS_OS_H
