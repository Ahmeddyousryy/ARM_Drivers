/****************************************************************/
/*     Author   :  Ahmed Yousry                                 */
/*     Date     :  13 Aug 2023                                  */
/*     Version  :  V02                                          */
/****************************************************************/

#ifndef MCAL_NVIC_NVIC_PRIVATE_H_
#define MCAL_NVIC_NVIC_PRIVATE_H_

/*                         BASE ADDRESS                   */
#define NVIC_BASE_ADDRESS                    0xE000E100
#define SCB_BASE_ADDRESS                     0xE000ED00

/*                      REGISTER DESCRIPTION              */

#define NVIC_ISER0                       *((volatile u32*)(NVIC_BASE_ADDRESS + 0x000))
#define NVIC_ISER1                       *((volatile u32*)(NVIC_BASE_ADDRESS + 0x004))

#define NVIC_ICER0                       *((volatile u32*)(NVIC_BASE_ADDRESS + 0x080))
#define NVIC_ICER1                       *((volatile u32*)(NVIC_BASE_ADDRESS + 0x084))

#define NVIC_ISPR0                       *((volatile u32*)(NVIC_BASE_ADDRESS + 0x100))
#define NVIC_ISPR1                       *((volatile u32*)(NVIC_BASE_ADDRESS + 0x104))

#define NVIC_ICPR0                       *((volatile u32*)(NVIC_BASE_ADDRESS + 0x180))
#define NVIC_ICPR1                       *((volatile u32*)(NVIC_BASE_ADDRESS + 0x184))

#define NVIC_IABR0                       *((volatile u32*)(NVIC_BASE_ADDRESS + 0x200))
#define NVIC_IABR1                       *((volatile u32*)(NVIC_BASE_ADDRESS + 0x204))

// NVIC_IPR  --> Pointer to IPR Base Address
#define NVIC_IPR                          ((volatile u8*)(NVIC_BASE_ADDRESS + 0x300))


#define SCB_AIRCR                        *((volatile u32*)(SCB_BASE_ADDRESS + 0x0C))

/*                   SW Priority Configurations                         */
#define NVIC_4GROUP_0SUB                           0x05FA0300
#define NVIC_3GROUP_1SUB                           0x05FA0400
#define NVIC_2GROUP_2SUB                           0x05FA0500
#define NVIC_1GROUP_3SUB                           0x05FA0600
#define NVIC_0GROUP_4SUB                           0x05FA0700

#endif /* MCAL_NVIC_NVIC_PRIVATE_H_ */
