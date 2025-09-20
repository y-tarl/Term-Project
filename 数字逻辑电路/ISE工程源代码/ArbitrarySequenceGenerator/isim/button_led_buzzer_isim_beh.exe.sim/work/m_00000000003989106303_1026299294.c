/**********************************************************************/
/*   ____  ____                                                       */
/*  /   /\/   /                                                       */
/* /___/  \  /                                                        */
/* \   \   \/                                                       */
/*  \   \        Copyright (c) 2003-2009 Xilinx, Inc.                */
/*  /   /          All Right Reserved.                                 */
/* /---/   /\                                                         */
/* \   \  /  \                                                      */
/*  \___\/\___\                                                    */
/***********************************************************************/

/* This file is designed for use with ISim build 0x7708f090 */

#define XSI_HIDE_SYMBOL_SPEC true
#include "xsi.h"
#include <memory.h>
#ifdef __GNUC__
#include <stdlib.h>
#else
#include <malloc.h>
#define alloca _alloca
#endif
static const char *ng0 = "C:/Users/Lenovo/Desktop/ArbitrarySequenceGenerator/button_led_buzzer.v";
static unsigned int ng1[] = {100000000U, 0U};
static unsigned int ng2[] = {0U, 0U};
static unsigned int ng3[] = {1U, 0U};
static unsigned int ng4[] = {100000U, 0U};
static unsigned int ng5[] = {3U, 0U};
static unsigned int ng6[] = {2U, 0U};
static unsigned int ng7[] = {14U, 0U};
static unsigned int ng8[] = {13U, 0U};
static unsigned int ng9[] = {5U, 0U};
static unsigned int ng10[] = {11U, 0U};
static unsigned int ng11[] = {9U, 0U};
static unsigned int ng12[] = {7U, 0U};
static unsigned int ng13[] = {15U, 0U};
static unsigned int ng14[] = {17U, 0U};
static unsigned int ng15[] = {6U, 0U};
static unsigned int ng16[] = {10U, 0U};
static unsigned int ng17[] = {4U, 0U};
static unsigned int ng18[] = {8U, 0U};
static unsigned int ng19[] = {12U, 0U};
static unsigned int ng20[] = {16U, 0U};
static unsigned int ng21[] = {60000U, 0U};
static unsigned int ng22[] = {20000U, 0U};
static int ng23[] = {1, 0};
static int ng24[] = {0, 0};
static int ng25[] = {8, 0};



static void Always_38_0(char *t0)
{
    char t8[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    char *t9;
    char *t10;
    unsigned int t11;
    unsigned int t12;
    unsigned int t13;
    unsigned int t14;
    unsigned int t15;
    unsigned int t16;
    unsigned int t17;
    unsigned int t18;
    unsigned int t19;
    unsigned int t20;
    unsigned int t21;
    unsigned int t22;
    char *t23;
    char *t24;
    unsigned int t25;
    unsigned int t26;
    unsigned int t27;
    unsigned int t28;
    unsigned int t29;
    char *t30;
    char *t31;

LAB0:    t1 = (t0 + 5472U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(38, ng0);
    t2 = (t0 + 8024);
    *((int *)t2) = 1;
    t3 = (t0 + 5504);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(39, ng0);
    t4 = (t0 + 2792);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = ((char*)((ng1)));
    memset(t8, 0, 8);
    t9 = (t6 + 4);
    t10 = (t7 + 4);
    t11 = *((unsigned int *)t6);
    t12 = *((unsigned int *)t7);
    t13 = (t11 ^ t12);
    t14 = *((unsigned int *)t9);
    t15 = *((unsigned int *)t10);
    t16 = (t14 ^ t15);
    t17 = (t13 | t16);
    t18 = *((unsigned int *)t9);
    t19 = *((unsigned int *)t10);
    t20 = (t18 | t19);
    t21 = (~(t20));
    t22 = (t17 & t21);
    if (t22 != 0)
        goto LAB8;

LAB5:    if (t20 != 0)
        goto LAB7;

LAB6:    *((unsigned int *)t8) = 1;

LAB8:    t24 = (t8 + 4);
    t25 = *((unsigned int *)t24);
    t26 = (~(t25));
    t27 = *((unsigned int *)t8);
    t28 = (t27 & t26);
    t29 = (t28 != 0);
    if (t29 > 0)
        goto LAB9;

LAB10:    xsi_set_current_line(42, ng0);
    t2 = (t0 + 2792);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng3)));
    memset(t8, 0, 8);
    xsi_vlog_unsigned_add(t8, 32, t4, 32, t5, 32);
    t6 = (t0 + 2792);
    xsi_vlogvar_wait_assign_value(t6, t8, 0, 0, 32, 0LL);

LAB11:    goto LAB2;

LAB7:    t23 = (t8 + 4);
    *((unsigned int *)t8) = 1;
    *((unsigned int *)t23) = 1;
    goto LAB8;

LAB9:    xsi_set_current_line(40, ng0);
    t30 = ((char*)((ng2)));
    t31 = (t0 + 2792);
    xsi_vlogvar_wait_assign_value(t31, t30, 0, 0, 32, 0LL);
    goto LAB11;

}

static void Always_48_1(char *t0)
{
    char t8[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    char *t9;
    char *t10;
    unsigned int t11;
    unsigned int t12;
    unsigned int t13;
    unsigned int t14;
    unsigned int t15;
    unsigned int t16;
    unsigned int t17;
    unsigned int t18;
    unsigned int t19;
    unsigned int t20;
    unsigned int t21;
    unsigned int t22;
    char *t23;
    char *t24;
    unsigned int t25;
    unsigned int t26;
    unsigned int t27;
    unsigned int t28;
    unsigned int t29;
    char *t30;
    char *t31;

LAB0:    t1 = (t0 + 5720U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(48, ng0);
    t2 = (t0 + 8040);
    *((int *)t2) = 1;
    t3 = (t0 + 5752);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(49, ng0);
    t4 = (t0 + 2952);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = ((char*)((ng4)));
    memset(t8, 0, 8);
    t9 = (t6 + 4);
    t10 = (t7 + 4);
    t11 = *((unsigned int *)t6);
    t12 = *((unsigned int *)t7);
    t13 = (t11 ^ t12);
    t14 = *((unsigned int *)t9);
    t15 = *((unsigned int *)t10);
    t16 = (t14 ^ t15);
    t17 = (t13 | t16);
    t18 = *((unsigned int *)t9);
    t19 = *((unsigned int *)t10);
    t20 = (t18 | t19);
    t21 = (~(t20));
    t22 = (t17 & t21);
    if (t22 != 0)
        goto LAB8;

LAB5:    if (t20 != 0)
        goto LAB7;

LAB6:    *((unsigned int *)t8) = 1;

LAB8:    t24 = (t8 + 4);
    t25 = *((unsigned int *)t24);
    t26 = (~(t25));
    t27 = *((unsigned int *)t8);
    t28 = (t27 & t26);
    t29 = (t28 != 0);
    if (t29 > 0)
        goto LAB9;

LAB10:    xsi_set_current_line(55, ng0);

LAB13:    xsi_set_current_line(56, ng0);
    t2 = (t0 + 2952);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng3)));
    memset(t8, 0, 8);
    xsi_vlog_unsigned_add(t8, 17, t4, 17, t5, 17);
    t6 = (t0 + 2952);
    xsi_vlogvar_wait_assign_value(t6, t8, 0, 0, 17, 0LL);
    xsi_set_current_line(57, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 3112);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 1, 0LL);

LAB11:    goto LAB2;

LAB7:    t23 = (t8 + 4);
    *((unsigned int *)t8) = 1;
    *((unsigned int *)t23) = 1;
    goto LAB8;

LAB9:    xsi_set_current_line(50, ng0);

LAB12:    xsi_set_current_line(51, ng0);
    t30 = ((char*)((ng2)));
    t31 = (t0 + 2952);
    xsi_vlogvar_wait_assign_value(t31, t30, 0, 0, 17, 0LL);
    xsi_set_current_line(52, ng0);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 3112);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 1, 0LL);
    goto LAB11;

}

static void Always_62_2(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    int t8;
    char *t9;
    char *t10;
    char *t11;
    char *t12;
    unsigned int t13;
    unsigned int t14;
    unsigned int t15;
    unsigned int t16;
    unsigned int t17;
    char *t18;
    char *t19;

LAB0:    t1 = (t0 + 5968U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(62, ng0);
    t2 = (t0 + 8056);
    *((int *)t2) = 1;
    t3 = (t0 + 6000);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(63, ng0);

LAB5:    xsi_set_current_line(64, ng0);
    t4 = (t0 + 3272);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);

LAB6:    t7 = ((char*)((ng2)));
    t8 = xsi_vlog_unsigned_case_compare(t6, 3, t7, 3);
    if (t8 == 1)
        goto LAB7;

LAB8:    t2 = ((char*)((ng3)));
    t8 = xsi_vlog_unsigned_case_compare(t6, 3, t2, 3);
    if (t8 == 1)
        goto LAB9;

LAB10:    t2 = ((char*)((ng5)));
    t8 = xsi_vlog_unsigned_case_compare(t6, 3, t2, 3);
    if (t8 == 1)
        goto LAB11;

LAB12:    t2 = ((char*)((ng6)));
    t8 = xsi_vlog_unsigned_case_compare(t6, 3, t2, 3);
    if (t8 == 1)
        goto LAB13;

LAB14:
LAB16:
LAB15:    xsi_set_current_line(86, ng0);
    t2 = (t0 + 3272);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 3272);
    xsi_vlogvar_wait_assign_value(t5, t4, 0, 0, 3, 0LL);

LAB17:    goto LAB2;

LAB7:    xsi_set_current_line(66, ng0);
    t9 = (t0 + 3112);
    t10 = (t9 + 56U);
    t11 = *((char **)t10);
    t12 = (t11 + 4);
    t13 = *((unsigned int *)t12);
    t14 = (~(t13));
    t15 = *((unsigned int *)t11);
    t16 = (t15 & t14);
    t17 = (t16 != 0);
    if (t17 > 0)
        goto LAB18;

LAB19:    xsi_set_current_line(69, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 3272);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 3, 0LL);

LAB20:    goto LAB17;

LAB9:    xsi_set_current_line(71, ng0);
    t3 = (t0 + 3112);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    t7 = (t5 + 4);
    t13 = *((unsigned int *)t7);
    t14 = (~(t13));
    t15 = *((unsigned int *)t5);
    t16 = (t15 & t14);
    t17 = (t16 != 0);
    if (t17 > 0)
        goto LAB21;

LAB22:    xsi_set_current_line(74, ng0);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 3272);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 3, 0LL);

LAB23:    goto LAB17;

LAB11:    xsi_set_current_line(76, ng0);
    t3 = (t0 + 3112);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    t7 = (t5 + 4);
    t13 = *((unsigned int *)t7);
    t14 = (~(t13));
    t15 = *((unsigned int *)t5);
    t16 = (t15 & t14);
    t17 = (t16 != 0);
    if (t17 > 0)
        goto LAB24;

LAB25:    xsi_set_current_line(79, ng0);
    t2 = ((char*)((ng5)));
    t3 = (t0 + 3272);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 3, 0LL);

LAB26:    goto LAB17;

LAB13:    xsi_set_current_line(81, ng0);
    t3 = (t0 + 3112);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    t7 = (t5 + 4);
    t13 = *((unsigned int *)t7);
    t14 = (~(t13));
    t15 = *((unsigned int *)t5);
    t16 = (t15 & t14);
    t17 = (t16 != 0);
    if (t17 > 0)
        goto LAB27;

LAB28:    xsi_set_current_line(84, ng0);
    t2 = ((char*)((ng6)));
    t3 = (t0 + 3272);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 3, 0LL);

LAB29:    goto LAB17;

LAB18:    xsi_set_current_line(67, ng0);
    t18 = ((char*)((ng3)));
    t19 = (t0 + 3272);
    xsi_vlogvar_wait_assign_value(t19, t18, 0, 0, 3, 0LL);
    goto LAB20;

LAB21:    xsi_set_current_line(72, ng0);
    t9 = ((char*)((ng5)));
    t10 = (t0 + 3272);
    xsi_vlogvar_wait_assign_value(t10, t9, 0, 0, 3, 0LL);
    goto LAB23;

LAB24:    xsi_set_current_line(77, ng0);
    t9 = ((char*)((ng6)));
    t10 = (t0 + 3272);
    xsi_vlogvar_wait_assign_value(t10, t9, 0, 0, 3, 0LL);
    goto LAB26;

LAB27:    xsi_set_current_line(82, ng0);
    t9 = ((char*)((ng2)));
    t10 = (t0 + 3272);
    xsi_vlogvar_wait_assign_value(t10, t9, 0, 0, 3, 0LL);
    goto LAB29;

}

static void Always_92_3(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    int t8;
    char *t9;
    char *t10;

LAB0:    t1 = (t0 + 6216U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(92, ng0);
    t2 = (t0 + 8072);
    *((int *)t2) = 1;
    t3 = (t0 + 6248);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(93, ng0);

LAB5:    xsi_set_current_line(94, ng0);
    t4 = (t0 + 3272);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);

LAB6:    t7 = ((char*)((ng2)));
    t8 = xsi_vlog_unsigned_case_compare(t6, 3, t7, 3);
    if (t8 == 1)
        goto LAB7;

LAB8:    t2 = ((char*)((ng3)));
    t8 = xsi_vlog_unsigned_case_compare(t6, 3, t2, 3);
    if (t8 == 1)
        goto LAB9;

LAB10:    t2 = ((char*)((ng5)));
    t8 = xsi_vlog_unsigned_case_compare(t6, 3, t2, 3);
    if (t8 == 1)
        goto LAB11;

LAB12:    t2 = ((char*)((ng6)));
    t8 = xsi_vlog_unsigned_case_compare(t6, 3, t2, 3);
    if (t8 == 1)
        goto LAB13;

LAB14:
LAB16:
LAB15:    xsi_set_current_line(135, ng0);

LAB70:    xsi_set_current_line(136, ng0);
    t2 = ((char*)((ng13)));
    t9 = (t0 + 2472);
    xsi_vlogvar_wait_assign_value(t9, t2, 0, 0, 4, 0LL);
    xsi_set_current_line(137, ng0);
    t2 = ((char*)((ng14)));
    t9 = (t0 + 3432);
    xsi_vlogvar_wait_assign_value(t9, t2, 0, 0, 5, 0LL);

LAB17:    goto LAB2;

LAB7:    xsi_set_current_line(95, ng0);

LAB18:    xsi_set_current_line(96, ng0);
    t9 = ((char*)((ng7)));
    t10 = (t0 + 2472);
    xsi_vlogvar_wait_assign_value(t10, t9, 0, 0, 4, 0LL);
    xsi_set_current_line(97, ng0);
    t2 = (t0 + 1752U);
    t3 = *((char **)t2);

LAB19:    t2 = ((char*)((ng7)));
    t8 = xsi_vlog_unsigned_case_compare(t3, 4, t2, 4);
    if (t8 == 1)
        goto LAB20;

LAB21:    t2 = ((char*)((ng8)));
    t8 = xsi_vlog_unsigned_case_compare(t3, 4, t2, 4);
    if (t8 == 1)
        goto LAB22;

LAB23:    t2 = ((char*)((ng10)));
    t8 = xsi_vlog_unsigned_case_compare(t3, 4, t2, 4);
    if (t8 == 1)
        goto LAB24;

LAB25:    t2 = ((char*)((ng12)));
    t8 = xsi_vlog_unsigned_case_compare(t3, 4, t2, 4);
    if (t8 == 1)
        goto LAB26;

LAB27:    t2 = ((char*)((ng13)));
    t8 = xsi_vlog_unsigned_case_compare(t3, 4, t2, 4);
    if (t8 == 1)
        goto LAB28;

LAB29:
LAB30:    goto LAB17;

LAB9:    xsi_set_current_line(105, ng0);

LAB31:    xsi_set_current_line(106, ng0);
    t4 = ((char*)((ng8)));
    t5 = (t0 + 2472);
    xsi_vlogvar_wait_assign_value(t5, t4, 0, 0, 4, 0LL);
    xsi_set_current_line(107, ng0);
    t2 = (t0 + 1752U);
    t4 = *((char **)t2);

LAB32:    t2 = ((char*)((ng7)));
    t8 = xsi_vlog_unsigned_case_compare(t4, 4, t2, 4);
    if (t8 == 1)
        goto LAB33;

LAB34:    t2 = ((char*)((ng8)));
    t8 = xsi_vlog_unsigned_case_compare(t4, 4, t2, 4);
    if (t8 == 1)
        goto LAB35;

LAB36:    t2 = ((char*)((ng10)));
    t8 = xsi_vlog_unsigned_case_compare(t4, 4, t2, 4);
    if (t8 == 1)
        goto LAB37;

LAB38:    t2 = ((char*)((ng12)));
    t8 = xsi_vlog_unsigned_case_compare(t4, 4, t2, 4);
    if (t8 == 1)
        goto LAB39;

LAB40:    t2 = ((char*)((ng13)));
    t8 = xsi_vlog_unsigned_case_compare(t4, 4, t2, 4);
    if (t8 == 1)
        goto LAB41;

LAB42:
LAB43:    goto LAB17;

LAB11:    xsi_set_current_line(115, ng0);

LAB44:    xsi_set_current_line(116, ng0);
    t5 = ((char*)((ng10)));
    t7 = (t0 + 2472);
    xsi_vlogvar_wait_assign_value(t7, t5, 0, 0, 4, 0LL);
    xsi_set_current_line(117, ng0);
    t2 = (t0 + 1752U);
    t5 = *((char **)t2);

LAB45:    t2 = ((char*)((ng7)));
    t8 = xsi_vlog_unsigned_case_compare(t5, 4, t2, 4);
    if (t8 == 1)
        goto LAB46;

LAB47:    t2 = ((char*)((ng8)));
    t8 = xsi_vlog_unsigned_case_compare(t5, 4, t2, 4);
    if (t8 == 1)
        goto LAB48;

LAB49:    t2 = ((char*)((ng10)));
    t8 = xsi_vlog_unsigned_case_compare(t5, 4, t2, 4);
    if (t8 == 1)
        goto LAB50;

LAB51:    t2 = ((char*)((ng12)));
    t8 = xsi_vlog_unsigned_case_compare(t5, 4, t2, 4);
    if (t8 == 1)
        goto LAB52;

LAB53:    t2 = ((char*)((ng13)));
    t8 = xsi_vlog_unsigned_case_compare(t5, 4, t2, 4);
    if (t8 == 1)
        goto LAB54;

LAB55:
LAB56:    goto LAB17;

LAB13:    xsi_set_current_line(125, ng0);

LAB57:    xsi_set_current_line(126, ng0);
    t7 = ((char*)((ng12)));
    t9 = (t0 + 2472);
    xsi_vlogvar_wait_assign_value(t9, t7, 0, 0, 4, 0LL);
    xsi_set_current_line(127, ng0);
    t2 = (t0 + 1752U);
    t7 = *((char **)t2);

LAB58:    t2 = ((char*)((ng7)));
    t8 = xsi_vlog_unsigned_case_compare(t7, 4, t2, 4);
    if (t8 == 1)
        goto LAB59;

LAB60:    t2 = ((char*)((ng8)));
    t8 = xsi_vlog_unsigned_case_compare(t7, 4, t2, 4);
    if (t8 == 1)
        goto LAB61;

LAB62:    t2 = ((char*)((ng10)));
    t8 = xsi_vlog_unsigned_case_compare(t7, 4, t2, 4);
    if (t8 == 1)
        goto LAB63;

LAB64:    t2 = ((char*)((ng12)));
    t8 = xsi_vlog_unsigned_case_compare(t7, 4, t2, 4);
    if (t8 == 1)
        goto LAB65;

LAB66:    t2 = ((char*)((ng13)));
    t8 = xsi_vlog_unsigned_case_compare(t7, 4, t2, 4);
    if (t8 == 1)
        goto LAB67;

LAB68:
LAB69:    goto LAB17;

LAB20:    xsi_set_current_line(98, ng0);
    t4 = ((char*)((ng3)));
    t5 = (t0 + 3432);
    xsi_vlogvar_wait_assign_value(t5, t4, 0, 0, 5, 0LL);
    goto LAB30;

LAB22:    xsi_set_current_line(99, ng0);
    t4 = ((char*)((ng9)));
    t5 = (t0 + 3432);
    xsi_vlogvar_wait_assign_value(t5, t4, 0, 0, 5, 0LL);
    goto LAB30;

LAB24:    xsi_set_current_line(100, ng0);
    t4 = ((char*)((ng11)));
    t5 = (t0 + 3432);
    xsi_vlogvar_wait_assign_value(t5, t4, 0, 0, 5, 0LL);
    goto LAB30;

LAB26:    xsi_set_current_line(101, ng0);
    t4 = ((char*)((ng8)));
    t5 = (t0 + 3432);
    xsi_vlogvar_wait_assign_value(t5, t4, 0, 0, 5, 0LL);
    goto LAB30;

LAB28:    xsi_set_current_line(102, ng0);
    t4 = ((char*)((ng14)));
    t5 = (t0 + 3432);
    xsi_vlogvar_wait_assign_value(t5, t4, 0, 0, 5, 0LL);
    goto LAB30;

LAB33:    xsi_set_current_line(108, ng0);
    t5 = ((char*)((ng6)));
    t7 = (t0 + 3432);
    xsi_vlogvar_wait_assign_value(t7, t5, 0, 0, 5, 0LL);
    goto LAB43;

LAB35:    xsi_set_current_line(109, ng0);
    t5 = ((char*)((ng15)));
    t7 = (t0 + 3432);
    xsi_vlogvar_wait_assign_value(t7, t5, 0, 0, 5, 0LL);
    goto LAB43;

LAB37:    xsi_set_current_line(110, ng0);
    t5 = ((char*)((ng16)));
    t7 = (t0 + 3432);
    xsi_vlogvar_wait_assign_value(t7, t5, 0, 0, 5, 0LL);
    goto LAB43;

LAB39:    xsi_set_current_line(111, ng0);
    t5 = ((char*)((ng7)));
    t7 = (t0 + 3432);
    xsi_vlogvar_wait_assign_value(t7, t5, 0, 0, 5, 0LL);
    goto LAB43;

LAB41:    xsi_set_current_line(112, ng0);
    t5 = ((char*)((ng14)));
    t7 = (t0 + 3432);
    xsi_vlogvar_wait_assign_value(t7, t5, 0, 0, 5, 0LL);
    goto LAB43;

LAB46:    xsi_set_current_line(118, ng0);
    t7 = ((char*)((ng5)));
    t9 = (t0 + 3432);
    xsi_vlogvar_wait_assign_value(t9, t7, 0, 0, 5, 0LL);
    goto LAB56;

LAB48:    xsi_set_current_line(119, ng0);
    t7 = ((char*)((ng12)));
    t9 = (t0 + 3432);
    xsi_vlogvar_wait_assign_value(t9, t7, 0, 0, 5, 0LL);
    goto LAB56;

LAB50:    xsi_set_current_line(120, ng0);
    t7 = ((char*)((ng10)));
    t9 = (t0 + 3432);
    xsi_vlogvar_wait_assign_value(t9, t7, 0, 0, 5, 0LL);
    goto LAB56;

LAB52:    xsi_set_current_line(121, ng0);
    t7 = ((char*)((ng13)));
    t9 = (t0 + 3432);
    xsi_vlogvar_wait_assign_value(t9, t7, 0, 0, 5, 0LL);
    goto LAB56;

LAB54:    xsi_set_current_line(122, ng0);
    t7 = ((char*)((ng14)));
    t9 = (t0 + 3432);
    xsi_vlogvar_wait_assign_value(t9, t7, 0, 0, 5, 0LL);
    goto LAB56;

LAB59:    xsi_set_current_line(128, ng0);
    t9 = ((char*)((ng17)));
    t10 = (t0 + 3432);
    xsi_vlogvar_wait_assign_value(t10, t9, 0, 0, 5, 0LL);
    goto LAB69;

LAB61:    xsi_set_current_line(129, ng0);
    t9 = ((char*)((ng18)));
    t10 = (t0 + 3432);
    xsi_vlogvar_wait_assign_value(t10, t9, 0, 0, 5, 0LL);
    goto LAB69;

LAB63:    xsi_set_current_line(130, ng0);
    t9 = ((char*)((ng19)));
    t10 = (t0 + 3432);
    xsi_vlogvar_wait_assign_value(t10, t9, 0, 0, 5, 0LL);
    goto LAB69;

LAB65:    xsi_set_current_line(131, ng0);
    t9 = ((char*)((ng20)));
    t10 = (t0 + 3432);
    xsi_vlogvar_wait_assign_value(t10, t9, 0, 0, 5, 0LL);
    goto LAB69;

LAB67:    xsi_set_current_line(132, ng0);
    t9 = ((char*)((ng14)));
    t10 = (t0 + 3432);
    xsi_vlogvar_wait_assign_value(t10, t9, 0, 0, 5, 0LL);
    goto LAB69;

}

static void Always_144_4(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;

LAB0:    t1 = (t0 + 6464U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(144, ng0);
    t2 = (t0 + 8088);
    *((int *)t2) = 1;
    t3 = (t0 + 6496);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(145, ng0);
    t4 = (t0 + 3432);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = (t0 + 3592);
    xsi_vlogvar_wait_assign_value(t7, t6, 0, 0, 5, 0LL);
    goto LAB2;

}

static void Always_148_5(char *t0)
{
    char t8[8];
    char t34[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    char *t9;
    char *t10;
    unsigned int t11;
    unsigned int t12;
    unsigned int t13;
    unsigned int t14;
    unsigned int t15;
    unsigned int t16;
    unsigned int t17;
    unsigned int t18;
    unsigned int t19;
    unsigned int t20;
    unsigned int t21;
    unsigned int t22;
    char *t23;
    char *t24;
    unsigned int t25;
    unsigned int t26;
    unsigned int t27;
    unsigned int t28;
    unsigned int t29;
    char *t30;
    char *t31;
    char *t32;
    char *t33;
    char *t35;

LAB0:    t1 = (t0 + 6712U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(148, ng0);
    t2 = (t0 + 8104);
    *((int *)t2) = 1;
    t3 = (t0 + 6744);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(149, ng0);
    t4 = (t0 + 3752);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = ((char*)((ng21)));
    memset(t8, 0, 8);
    t9 = (t6 + 4);
    t10 = (t7 + 4);
    t11 = *((unsigned int *)t6);
    t12 = *((unsigned int *)t7);
    t13 = (t11 ^ t12);
    t14 = *((unsigned int *)t9);
    t15 = *((unsigned int *)t10);
    t16 = (t14 ^ t15);
    t17 = (t13 | t16);
    t18 = *((unsigned int *)t9);
    t19 = *((unsigned int *)t10);
    t20 = (t18 | t19);
    t21 = (~(t20));
    t22 = (t17 & t21);
    if (t22 != 0)
        goto LAB8;

LAB5:    if (t20 != 0)
        goto LAB7;

LAB6:    *((unsigned int *)t8) = 1;

LAB8:    t24 = (t8 + 4);
    t25 = *((unsigned int *)t24);
    t26 = (~(t25));
    t27 = *((unsigned int *)t8);
    t28 = (t27 & t26);
    t29 = (t28 != 0);
    if (t29 > 0)
        goto LAB9;

LAB10:    xsi_set_current_line(151, ng0);
    t2 = (t0 + 3592);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 3432);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    memset(t8, 0, 8);
    t9 = (t4 + 4);
    t10 = (t7 + 4);
    t11 = *((unsigned int *)t4);
    t12 = *((unsigned int *)t7);
    t13 = (t11 ^ t12);
    t14 = *((unsigned int *)t9);
    t15 = *((unsigned int *)t10);
    t16 = (t14 ^ t15);
    t17 = (t13 | t16);
    t18 = *((unsigned int *)t9);
    t19 = *((unsigned int *)t10);
    t20 = (t18 | t19);
    t21 = (~(t20));
    t22 = (t17 & t21);
    if (t22 != 0)
        goto LAB13;

LAB12:    if (t20 != 0)
        goto LAB14;

LAB15:    t24 = (t8 + 4);
    t25 = *((unsigned int *)t24);
    t26 = (~(t25));
    t27 = *((unsigned int *)t8);
    t28 = (t27 & t26);
    t29 = (t28 != 0);
    if (t29 > 0)
        goto LAB16;

LAB17:    xsi_set_current_line(153, ng0);
    t2 = (t0 + 3592);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 3432);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    memset(t8, 0, 8);
    t9 = (t4 + 4);
    t10 = (t7 + 4);
    t11 = *((unsigned int *)t4);
    t12 = *((unsigned int *)t7);
    t13 = (t11 ^ t12);
    t14 = *((unsigned int *)t9);
    t15 = *((unsigned int *)t10);
    t16 = (t14 ^ t15);
    t17 = (t13 | t16);
    t18 = *((unsigned int *)t9);
    t19 = *((unsigned int *)t10);
    t20 = (t18 | t19);
    t21 = (~(t20));
    t22 = (t17 & t21);
    if (t22 != 0)
        goto LAB22;

LAB19:    if (t20 != 0)
        goto LAB21;

LAB20:    *((unsigned int *)t8) = 1;

LAB22:    t24 = (t8 + 4);
    t25 = *((unsigned int *)t24);
    t26 = (~(t25));
    t27 = *((unsigned int *)t8);
    t28 = (t27 & t26);
    t29 = (t28 != 0);
    if (t29 > 0)
        goto LAB23;

LAB24:
LAB25:
LAB18:
LAB11:    goto LAB2;

LAB7:    t23 = (t8 + 4);
    *((unsigned int *)t8) = 1;
    *((unsigned int *)t23) = 1;
    goto LAB8;

LAB9:    xsi_set_current_line(150, ng0);
    t30 = ((char*)((ng2)));
    t31 = (t0 + 3752);
    xsi_vlogvar_wait_assign_value(t31, t30, 0, 0, 20, 0LL);
    goto LAB11;

LAB13:    *((unsigned int *)t8) = 1;
    goto LAB15;

LAB14:    t23 = (t8 + 4);
    *((unsigned int *)t8) = 1;
    *((unsigned int *)t23) = 1;
    goto LAB15;

LAB16:    xsi_set_current_line(152, ng0);
    t30 = ((char*)((ng2)));
    t31 = (t0 + 3752);
    xsi_vlogvar_wait_assign_value(t31, t30, 0, 0, 20, 0LL);
    goto LAB18;

LAB21:    t23 = (t8 + 4);
    *((unsigned int *)t8) = 1;
    *((unsigned int *)t23) = 1;
    goto LAB22;

LAB23:    xsi_set_current_line(154, ng0);
    t30 = (t0 + 3752);
    t31 = (t30 + 56U);
    t32 = *((char **)t31);
    t33 = ((char*)((ng3)));
    memset(t34, 0, 8);
    xsi_vlog_unsigned_add(t34, 20, t32, 20, t33, 20);
    t35 = (t0 + 3752);
    xsi_vlogvar_wait_assign_value(t35, t34, 0, 0, 20, 0LL);
    goto LAB25;

}

static void Always_157_6(char *t0)
{
    char t8[8];
    char t12[8];
    char t28[8];
    char t44[8];
    char t52[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    char *t9;
    char *t10;
    char *t11;
    char *t13;
    unsigned int t14;
    unsigned int t15;
    unsigned int t16;
    unsigned int t17;
    unsigned int t18;
    char *t19;
    char *t20;
    unsigned int t21;
    unsigned int t22;
    unsigned int t23;
    char *t24;
    char *t25;
    char *t26;
    char *t27;
    char *t29;
    char *t30;
    unsigned int t31;
    unsigned int t32;
    unsigned int t33;
    unsigned int t34;
    unsigned int t35;
    unsigned int t36;
    unsigned int t37;
    unsigned int t38;
    unsigned int t39;
    unsigned int t40;
    unsigned int t41;
    unsigned int t42;
    char *t43;
    char *t45;
    unsigned int t46;
    unsigned int t47;
    unsigned int t48;
    unsigned int t49;
    unsigned int t50;
    char *t51;
    unsigned int t53;
    unsigned int t54;
    unsigned int t55;
    char *t56;
    char *t57;
    char *t58;
    unsigned int t59;
    unsigned int t60;
    unsigned int t61;
    unsigned int t62;
    unsigned int t63;
    unsigned int t64;
    unsigned int t65;
    char *t66;
    char *t67;
    unsigned int t68;
    unsigned int t69;
    unsigned int t70;
    unsigned int t71;
    unsigned int t72;
    unsigned int t73;
    unsigned int t74;
    unsigned int t75;
    int t76;
    int t77;
    unsigned int t78;
    unsigned int t79;
    unsigned int t80;
    unsigned int t81;
    unsigned int t82;
    unsigned int t83;
    char *t84;
    unsigned int t85;
    unsigned int t86;
    unsigned int t87;
    unsigned int t88;
    unsigned int t89;
    char *t90;
    char *t91;
    char *t92;
    char *t93;

LAB0:    t1 = (t0 + 6960U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(157, ng0);
    t2 = (t0 + 8120);
    *((int *)t2) = 1;
    t3 = (t0 + 6992);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(158, ng0);
    t4 = (t0 + 3752);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = ((char*)((ng22)));
    memset(t8, 0, 8);
    t9 = (t6 + 4);
    if (*((unsigned int *)t9) != 0)
        goto LAB6;

LAB5:    t10 = (t7 + 4);
    if (*((unsigned int *)t10) != 0)
        goto LAB6;

LAB9:    if (*((unsigned int *)t6) < *((unsigned int *)t7))
        goto LAB8;

LAB7:    *((unsigned int *)t8) = 1;

LAB8:    memset(t12, 0, 8);
    t13 = (t8 + 4);
    t14 = *((unsigned int *)t13);
    t15 = (~(t14));
    t16 = *((unsigned int *)t8);
    t17 = (t16 & t15);
    t18 = (t17 & 1U);
    if (t18 != 0)
        goto LAB10;

LAB11:    if (*((unsigned int *)t13) != 0)
        goto LAB12;

LAB13:    t20 = (t12 + 4);
    t21 = *((unsigned int *)t12);
    t22 = *((unsigned int *)t20);
    t23 = (t21 || t22);
    if (t23 > 0)
        goto LAB14;

LAB15:    memcpy(t52, t12, 8);

LAB16:    t84 = (t52 + 4);
    t85 = *((unsigned int *)t84);
    t86 = (~(t85));
    t87 = *((unsigned int *)t52);
    t88 = (t87 & t86);
    t89 = (t88 != 0);
    if (t89 > 0)
        goto LAB28;

LAB29:    xsi_set_current_line(161, ng0);
    t2 = (t0 + 3912);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 3912);
    xsi_vlogvar_wait_assign_value(t5, t4, 0, 0, 5, 0LL);

LAB30:    goto LAB2;

LAB6:    t11 = (t8 + 4);
    *((unsigned int *)t8) = 1;
    *((unsigned int *)t11) = 1;
    goto LAB8;

LAB10:    *((unsigned int *)t12) = 1;
    goto LAB13;

LAB12:    t19 = (t12 + 4);
    *((unsigned int *)t12) = 1;
    *((unsigned int *)t19) = 1;
    goto LAB13;

LAB14:    t24 = (t0 + 3592);
    t25 = (t24 + 56U);
    t26 = *((char **)t25);
    t27 = ((char*)((ng14)));
    memset(t28, 0, 8);
    t29 = (t26 + 4);
    t30 = (t27 + 4);
    t31 = *((unsigned int *)t26);
    t32 = *((unsigned int *)t27);
    t33 = (t31 ^ t32);
    t34 = *((unsigned int *)t29);
    t35 = *((unsigned int *)t30);
    t36 = (t34 ^ t35);
    t37 = (t33 | t36);
    t38 = *((unsigned int *)t29);
    t39 = *((unsigned int *)t30);
    t40 = (t38 | t39);
    t41 = (~(t40));
    t42 = (t37 & t41);
    if (t42 != 0)
        goto LAB18;

LAB17:    if (t40 != 0)
        goto LAB19;

LAB20:    memset(t44, 0, 8);
    t45 = (t28 + 4);
    t46 = *((unsigned int *)t45);
    t47 = (~(t46));
    t48 = *((unsigned int *)t28);
    t49 = (t48 & t47);
    t50 = (t49 & 1U);
    if (t50 != 0)
        goto LAB21;

LAB22:    if (*((unsigned int *)t45) != 0)
        goto LAB23;

LAB24:    t53 = *((unsigned int *)t12);
    t54 = *((unsigned int *)t44);
    t55 = (t53 & t54);
    *((unsigned int *)t52) = t55;
    t56 = (t12 + 4);
    t57 = (t44 + 4);
    t58 = (t52 + 4);
    t59 = *((unsigned int *)t56);
    t60 = *((unsigned int *)t57);
    t61 = (t59 | t60);
    *((unsigned int *)t58) = t61;
    t62 = *((unsigned int *)t58);
    t63 = (t62 != 0);
    if (t63 == 1)
        goto LAB25;

LAB26:
LAB27:    goto LAB16;

LAB18:    *((unsigned int *)t28) = 1;
    goto LAB20;

LAB19:    t43 = (t28 + 4);
    *((unsigned int *)t28) = 1;
    *((unsigned int *)t43) = 1;
    goto LAB20;

LAB21:    *((unsigned int *)t44) = 1;
    goto LAB24;

LAB23:    t51 = (t44 + 4);
    *((unsigned int *)t44) = 1;
    *((unsigned int *)t51) = 1;
    goto LAB24;

LAB25:    t64 = *((unsigned int *)t52);
    t65 = *((unsigned int *)t58);
    *((unsigned int *)t52) = (t64 | t65);
    t66 = (t12 + 4);
    t67 = (t44 + 4);
    t68 = *((unsigned int *)t12);
    t69 = (~(t68));
    t70 = *((unsigned int *)t66);
    t71 = (~(t70));
    t72 = *((unsigned int *)t44);
    t73 = (~(t72));
    t74 = *((unsigned int *)t67);
    t75 = (~(t74));
    t76 = (t69 & t71);
    t77 = (t73 & t75);
    t78 = (~(t76));
    t79 = (~(t77));
    t80 = *((unsigned int *)t58);
    *((unsigned int *)t58) = (t80 & t78);
    t81 = *((unsigned int *)t58);
    *((unsigned int *)t58) = (t81 & t79);
    t82 = *((unsigned int *)t52);
    *((unsigned int *)t52) = (t82 & t78);
    t83 = *((unsigned int *)t52);
    *((unsigned int *)t52) = (t83 & t79);
    goto LAB27;

LAB28:    xsi_set_current_line(159, ng0);
    t90 = (t0 + 3592);
    t91 = (t90 + 56U);
    t92 = *((char **)t91);
    t93 = (t0 + 3912);
    xsi_vlogvar_wait_assign_value(t93, t92, 0, 0, 5, 0LL);
    goto LAB30;

}

static void Cont_166_7(char *t0)
{
    char t3[8];
    char t4[8];
    char t10[8];
    char *t1;
    char *t2;
    char *t5;
    char *t6;
    char *t7;
    char *t8;
    char *t9;
    char *t11;
    char *t12;
    unsigned int t13;
    unsigned int t14;
    unsigned int t15;
    unsigned int t16;
    unsigned int t17;
    unsigned int t18;
    unsigned int t19;
    unsigned int t20;
    unsigned int t21;
    unsigned int t22;
    unsigned int t23;
    unsigned int t24;
    char *t25;
    char *t26;
    unsigned int t27;
    unsigned int t28;
    unsigned int t29;
    unsigned int t30;
    unsigned int t31;
    char *t32;
    char *t33;
    unsigned int t34;
    unsigned int t35;
    unsigned int t36;
    char *t37;
    unsigned int t38;
    unsigned int t39;
    unsigned int t40;
    unsigned int t41;
    char *t42;
    char *t43;
    char *t44;
    char *t45;
    char *t46;
    char *t47;
    unsigned int t48;
    unsigned int t49;
    char *t50;
    unsigned int t51;
    unsigned int t52;
    char *t53;
    unsigned int t54;
    unsigned int t55;
    char *t56;

LAB0:    t1 = (t0 + 7208U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(166, ng0);
    t2 = (t0 + 3592);
    t5 = (t2 + 56U);
    t6 = *((char **)t5);
    t7 = (t0 + 3432);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    memset(t10, 0, 8);
    t11 = (t6 + 4);
    t12 = (t9 + 4);
    t13 = *((unsigned int *)t6);
    t14 = *((unsigned int *)t9);
    t15 = (t13 ^ t14);
    t16 = *((unsigned int *)t11);
    t17 = *((unsigned int *)t12);
    t18 = (t16 ^ t17);
    t19 = (t15 | t18);
    t20 = *((unsigned int *)t11);
    t21 = *((unsigned int *)t12);
    t22 = (t20 | t21);
    t23 = (~(t22));
    t24 = (t19 & t23);
    if (t24 != 0)
        goto LAB5;

LAB4:    if (t22 != 0)
        goto LAB6;

LAB7:    memset(t4, 0, 8);
    t26 = (t10 + 4);
    t27 = *((unsigned int *)t26);
    t28 = (~(t27));
    t29 = *((unsigned int *)t10);
    t30 = (t29 & t28);
    t31 = (t30 & 1U);
    if (t31 != 0)
        goto LAB8;

LAB9:    if (*((unsigned int *)t26) != 0)
        goto LAB10;

LAB11:    t33 = (t4 + 4);
    t34 = *((unsigned int *)t4);
    t35 = *((unsigned int *)t33);
    t36 = (t34 || t35);
    if (t36 > 0)
        goto LAB12;

LAB13:    t38 = *((unsigned int *)t4);
    t39 = (~(t38));
    t40 = *((unsigned int *)t33);
    t41 = (t39 || t40);
    if (t41 > 0)
        goto LAB14;

LAB15:    if (*((unsigned int *)t33) > 0)
        goto LAB16;

LAB17:    if (*((unsigned int *)t4) > 0)
        goto LAB18;

LAB19:    memcpy(t3, t42, 8);

LAB20:    t43 = (t0 + 8248);
    t44 = (t43 + 56U);
    t45 = *((char **)t44);
    t46 = (t45 + 56U);
    t47 = *((char **)t46);
    memset(t47, 0, 8);
    t48 = 1U;
    t49 = t48;
    t50 = (t3 + 4);
    t51 = *((unsigned int *)t3);
    t48 = (t48 & t51);
    t52 = *((unsigned int *)t50);
    t49 = (t49 & t52);
    t53 = (t47 + 4);
    t54 = *((unsigned int *)t47);
    *((unsigned int *)t47) = (t54 | t48);
    t55 = *((unsigned int *)t53);
    *((unsigned int *)t53) = (t55 | t49);
    xsi_driver_vfirst_trans(t43, 0, 0);
    t56 = (t0 + 8136);
    *((int *)t56) = 1;

LAB1:    return;
LAB5:    *((unsigned int *)t10) = 1;
    goto LAB7;

LAB6:    t25 = (t10 + 4);
    *((unsigned int *)t10) = 1;
    *((unsigned int *)t25) = 1;
    goto LAB7;

LAB8:    *((unsigned int *)t4) = 1;
    goto LAB11;

LAB10:    t32 = (t4 + 4);
    *((unsigned int *)t4) = 1;
    *((unsigned int *)t32) = 1;
    goto LAB11;

LAB12:    t37 = ((char*)((ng23)));
    goto LAB13;

LAB14:    t42 = ((char*)((ng24)));
    goto LAB15;

LAB16:    xsi_vlog_unsigned_bit_combine(t3, 32, t37, 32, t42, 32);
    goto LAB20;

LAB18:    memcpy(t3, t37, 8);
    goto LAB20;

}

static void Always_173_8(char *t0)
{
    char t8[8];
    char t12[8];
    char t28[8];
    char t32[8];
    char t40[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    char *t9;
    char *t10;
    char *t11;
    char *t13;
    unsigned int t14;
    unsigned int t15;
    unsigned int t16;
    unsigned int t17;
    unsigned int t18;
    char *t19;
    char *t20;
    unsigned int t21;
    unsigned int t22;
    unsigned int t23;
    char *t24;
    char *t25;
    char *t26;
    char *t27;
    char *t29;
    char *t30;
    char *t31;
    char *t33;
    unsigned int t34;
    unsigned int t35;
    unsigned int t36;
    unsigned int t37;
    unsigned int t38;
    char *t39;
    unsigned int t41;
    unsigned int t42;
    unsigned int t43;
    char *t44;
    char *t45;
    char *t46;
    unsigned int t47;
    unsigned int t48;
    unsigned int t49;
    unsigned int t50;
    unsigned int t51;
    unsigned int t52;
    unsigned int t53;
    char *t54;
    char *t55;
    unsigned int t56;
    unsigned int t57;
    unsigned int t58;
    unsigned int t59;
    unsigned int t60;
    unsigned int t61;
    unsigned int t62;
    unsigned int t63;
    int t64;
    int t65;
    unsigned int t66;
    unsigned int t67;
    unsigned int t68;
    unsigned int t69;
    unsigned int t70;
    unsigned int t71;
    char *t72;
    unsigned int t73;
    unsigned int t74;
    unsigned int t75;
    unsigned int t76;
    unsigned int t77;
    char *t78;
    char *t79;

LAB0:    t1 = (t0 + 7456U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(173, ng0);
    t2 = (t0 + 8152);
    *((int *)t2) = 1;
    t3 = (t0 + 7488);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(174, ng0);
    t4 = (t0 + 3912);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = ((char*)((ng3)));
    memset(t8, 0, 8);
    t9 = (t6 + 4);
    if (*((unsigned int *)t9) != 0)
        goto LAB6;

LAB5:    t10 = (t7 + 4);
    if (*((unsigned int *)t10) != 0)
        goto LAB6;

LAB9:    if (*((unsigned int *)t6) < *((unsigned int *)t7))
        goto LAB8;

LAB7:    *((unsigned int *)t8) = 1;

LAB8:    memset(t12, 0, 8);
    t13 = (t8 + 4);
    t14 = *((unsigned int *)t13);
    t15 = (~(t14));
    t16 = *((unsigned int *)t8);
    t17 = (t16 & t15);
    t18 = (t17 & 1U);
    if (t18 != 0)
        goto LAB10;

LAB11:    if (*((unsigned int *)t13) != 0)
        goto LAB12;

LAB13:    t20 = (t12 + 4);
    t21 = *((unsigned int *)t12);
    t22 = *((unsigned int *)t20);
    t23 = (t21 || t22);
    if (t23 > 0)
        goto LAB14;

LAB15:    memcpy(t40, t12, 8);

LAB16:    t72 = (t40 + 4);
    t73 = *((unsigned int *)t72);
    t74 = (~(t73));
    t75 = *((unsigned int *)t40);
    t76 = (t75 & t74);
    t77 = (t76 != 0);
    if (t77 > 0)
        goto LAB29;

LAB30:    xsi_set_current_line(182, ng0);
    t2 = (t0 + 3912);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng7)));
    memset(t8, 0, 8);
    t6 = (t4 + 4);
    t7 = (t5 + 4);
    t14 = *((unsigned int *)t4);
    t15 = *((unsigned int *)t5);
    t16 = (t14 ^ t15);
    t17 = *((unsigned int *)t6);
    t18 = *((unsigned int *)t7);
    t21 = (t17 ^ t18);
    t22 = (t16 | t21);
    t23 = *((unsigned int *)t6);
    t34 = *((unsigned int *)t7);
    t35 = (t23 | t34);
    t36 = (~(t35));
    t37 = (t22 & t36);
    if (t37 != 0)
        goto LAB49;

LAB46:    if (t35 != 0)
        goto LAB48;

LAB47:    *((unsigned int *)t8) = 1;

LAB49:    t10 = (t8 + 4);
    t38 = *((unsigned int *)t10);
    t41 = (~(t38));
    t42 = *((unsigned int *)t8);
    t43 = (t42 & t41);
    t47 = (t43 != 0);
    if (t47 > 0)
        goto LAB50;

LAB51:    xsi_set_current_line(186, ng0);
    t2 = (t0 + 3912);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng13)));
    memset(t8, 0, 8);
    t6 = (t4 + 4);
    t7 = (t5 + 4);
    t14 = *((unsigned int *)t4);
    t15 = *((unsigned int *)t5);
    t16 = (t14 ^ t15);
    t17 = *((unsigned int *)t6);
    t18 = *((unsigned int *)t7);
    t21 = (t17 ^ t18);
    t22 = (t16 | t21);
    t23 = *((unsigned int *)t6);
    t34 = *((unsigned int *)t7);
    t35 = (t23 | t34);
    t36 = (~(t35));
    t37 = (t22 & t36);
    if (t37 != 0)
        goto LAB57;

LAB54:    if (t35 != 0)
        goto LAB56;

LAB55:    *((unsigned int *)t8) = 1;

LAB57:    t10 = (t8 + 4);
    t38 = *((unsigned int *)t10);
    t41 = (~(t38));
    t42 = *((unsigned int *)t8);
    t43 = (t42 & t41);
    t47 = (t43 != 0);
    if (t47 > 0)
        goto LAB58;

LAB59:    xsi_set_current_line(193, ng0);
    t2 = (t0 + 3912);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng20)));
    memset(t8, 0, 8);
    t6 = (t4 + 4);
    t7 = (t5 + 4);
    t14 = *((unsigned int *)t4);
    t15 = *((unsigned int *)t5);
    t16 = (t14 ^ t15);
    t17 = *((unsigned int *)t6);
    t18 = *((unsigned int *)t7);
    t21 = (t17 ^ t18);
    t22 = (t16 | t21);
    t23 = *((unsigned int *)t6);
    t34 = *((unsigned int *)t7);
    t35 = (t23 | t34);
    t36 = (~(t35));
    t37 = (t22 & t36);
    if (t37 != 0)
        goto LAB65;

LAB62:    if (t35 != 0)
        goto LAB64;

LAB63:    *((unsigned int *)t8) = 1;

LAB65:    t10 = (t8 + 4);
    t38 = *((unsigned int *)t10);
    t41 = (~(t38));
    t42 = *((unsigned int *)t8);
    t43 = (t42 & t41);
    t47 = (t43 != 0);
    if (t47 > 0)
        goto LAB66;

LAB67:    xsi_set_current_line(213, ng0);
    t2 = (t0 + 3912);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng8)));
    memset(t8, 0, 8);
    t6 = (t4 + 4);
    t7 = (t5 + 4);
    t14 = *((unsigned int *)t4);
    t15 = *((unsigned int *)t5);
    t16 = (t14 ^ t15);
    t17 = *((unsigned int *)t6);
    t18 = *((unsigned int *)t7);
    t21 = (t17 ^ t18);
    t22 = (t16 | t21);
    t23 = *((unsigned int *)t6);
    t34 = *((unsigned int *)t7);
    t35 = (t23 | t34);
    t36 = (~(t35));
    t37 = (t22 & t36);
    if (t37 != 0)
        goto LAB98;

LAB95:    if (t35 != 0)
        goto LAB97;

LAB96:    *((unsigned int *)t8) = 1;

LAB98:    t10 = (t8 + 4);
    t38 = *((unsigned int *)t10);
    t41 = (~(t38));
    t42 = *((unsigned int *)t8);
    t43 = (t42 & t41);
    t47 = (t43 != 0);
    if (t47 > 0)
        goto LAB99;

LAB100:
LAB101:
LAB68:
LAB60:
LAB52:
LAB31:    goto LAB2;

LAB6:    t11 = (t8 + 4);
    *((unsigned int *)t8) = 1;
    *((unsigned int *)t11) = 1;
    goto LAB8;

LAB10:    *((unsigned int *)t12) = 1;
    goto LAB13;

LAB12:    t19 = (t12 + 4);
    *((unsigned int *)t12) = 1;
    *((unsigned int *)t19) = 1;
    goto LAB13;

LAB14:    t24 = (t0 + 3912);
    t25 = (t24 + 56U);
    t26 = *((char **)t25);
    t27 = ((char*)((ng18)));
    memset(t28, 0, 8);
    t29 = (t26 + 4);
    if (*((unsigned int *)t29) != 0)
        goto LAB18;

LAB17:    t30 = (t27 + 4);
    if (*((unsigned int *)t30) != 0)
        goto LAB18;

LAB21:    if (*((unsigned int *)t26) > *((unsigned int *)t27))
        goto LAB20;

LAB19:    *((unsigned int *)t28) = 1;

LAB20:    memset(t32, 0, 8);
    t33 = (t28 + 4);
    t34 = *((unsigned int *)t33);
    t35 = (~(t34));
    t36 = *((unsigned int *)t28);
    t37 = (t36 & t35);
    t38 = (t37 & 1U);
    if (t38 != 0)
        goto LAB22;

LAB23:    if (*((unsigned int *)t33) != 0)
        goto LAB24;

LAB25:    t41 = *((unsigned int *)t12);
    t42 = *((unsigned int *)t32);
    t43 = (t41 & t42);
    *((unsigned int *)t40) = t43;
    t44 = (t12 + 4);
    t45 = (t32 + 4);
    t46 = (t40 + 4);
    t47 = *((unsigned int *)t44);
    t48 = *((unsigned int *)t45);
    t49 = (t47 | t48);
    *((unsigned int *)t46) = t49;
    t50 = *((unsigned int *)t46);
    t51 = (t50 != 0);
    if (t51 == 1)
        goto LAB26;

LAB27:
LAB28:    goto LAB16;

LAB18:    t31 = (t28 + 4);
    *((unsigned int *)t28) = 1;
    *((unsigned int *)t31) = 1;
    goto LAB20;

LAB22:    *((unsigned int *)t32) = 1;
    goto LAB25;

LAB24:    t39 = (t32 + 4);
    *((unsigned int *)t32) = 1;
    *((unsigned int *)t39) = 1;
    goto LAB25;

LAB26:    t52 = *((unsigned int *)t40);
    t53 = *((unsigned int *)t46);
    *((unsigned int *)t40) = (t52 | t53);
    t54 = (t12 + 4);
    t55 = (t32 + 4);
    t56 = *((unsigned int *)t12);
    t57 = (~(t56));
    t58 = *((unsigned int *)t54);
    t59 = (~(t58));
    t60 = *((unsigned int *)t32);
    t61 = (~(t60));
    t62 = *((unsigned int *)t55);
    t63 = (~(t62));
    t64 = (t57 & t59);
    t65 = (t61 & t63);
    t66 = (~(t64));
    t67 = (~(t65));
    t68 = *((unsigned int *)t46);
    *((unsigned int *)t46) = (t68 & t66);
    t69 = *((unsigned int *)t46);
    *((unsigned int *)t46) = (t69 & t67);
    t70 = *((unsigned int *)t40);
    *((unsigned int *)t40) = (t70 & t66);
    t71 = *((unsigned int *)t40);
    *((unsigned int *)t40) = (t71 & t67);
    goto LAB28;

LAB29:    xsi_set_current_line(175, ng0);

LAB32:    xsi_set_current_line(176, ng0);
    xsi_set_current_line(176, ng0);
    t78 = ((char*)((ng24)));
    t79 = (t0 + 4552);
    xsi_vlogvar_assign_value(t79, t78, 0, 0, 32);

LAB33:    t2 = (t0 + 4552);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng25)));
    memset(t8, 0, 8);
    xsi_vlog_signed_less(t8, 32, t4, 32, t5, 32);
    t6 = (t8 + 4);
    t14 = *((unsigned int *)t6);
    t15 = (~(t14));
    t16 = *((unsigned int *)t8);
    t17 = (t16 & t15);
    t18 = (t17 != 0);
    if (t18 > 0)
        goto LAB34;

LAB35:    goto LAB31;

LAB34:    xsi_set_current_line(177, ng0);

LAB36:    xsi_set_current_line(178, ng0);
    t7 = (t0 + 4552);
    t9 = (t7 + 56U);
    t10 = *((char **)t9);
    t11 = (t0 + 3912);
    t13 = (t11 + 56U);
    t19 = *((char **)t13);
    t20 = ((char*)((ng23)));
    memset(t12, 0, 8);
    xsi_vlog_unsigned_minus(t12, 32, t19, 5, t20, 32);
    memset(t28, 0, 8);
    t24 = (t10 + 4);
    t25 = (t12 + 4);
    t21 = *((unsigned int *)t10);
    t22 = *((unsigned int *)t12);
    t23 = (t21 ^ t22);
    t34 = *((unsigned int *)t24);
    t35 = *((unsigned int *)t25);
    t36 = (t34 ^ t35);
    t37 = (t23 | t36);
    t38 = *((unsigned int *)t24);
    t41 = *((unsigned int *)t25);
    t42 = (t38 | t41);
    t43 = (~(t42));
    t47 = (t37 & t43);
    if (t47 != 0)
        goto LAB40;

LAB37:    if (t42 != 0)
        goto LAB39;

LAB38:    *((unsigned int *)t28) = 1;

LAB40:    t27 = (t28 + 4);
    t48 = *((unsigned int *)t27);
    t49 = (~(t48));
    t50 = *((unsigned int *)t28);
    t51 = (t50 & t49);
    t52 = (t51 != 0);
    if (t52 > 0)
        goto LAB41;

LAB42:
LAB43:    xsi_set_current_line(176, ng0);
    t2 = (t0 + 4552);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng23)));
    memset(t8, 0, 8);
    xsi_vlog_signed_add(t8, 32, t4, 32, t5, 32);
    t6 = (t0 + 4552);
    xsi_vlogvar_assign_value(t6, t8, 0, 0, 32);
    goto LAB33;

LAB39:    t26 = (t28 + 4);
    *((unsigned int *)t28) = 1;
    *((unsigned int *)t26) = 1;
    goto LAB40;

LAB41:    xsi_set_current_line(179, ng0);
    t29 = ((char*)((ng3)));
    t30 = (t0 + 4072);
    t31 = (t0 + 4072);
    t33 = (t31 + 72U);
    t39 = *((char **)t33);
    t44 = (t0 + 4552);
    t45 = (t44 + 56U);
    t46 = *((char **)t45);
    xsi_vlog_generic_convert_bit_index(t32, t39, 2, t46, 32, 1);
    t54 = (t32 + 4);
    t53 = *((unsigned int *)t54);
    t64 = (!(t53));
    if (t64 == 1)
        goto LAB44;

LAB45:    goto LAB43;

LAB44:    xsi_vlogvar_assign_value(t30, t29, 0, *((unsigned int *)t32), 1);
    goto LAB45;

LAB48:    t9 = (t8 + 4);
    *((unsigned int *)t8) = 1;
    *((unsigned int *)t9) = 1;
    goto LAB49;

LAB50:    xsi_set_current_line(183, ng0);

LAB53:    xsi_set_current_line(184, ng0);
    t11 = (t0 + 4072);
    t13 = (t11 + 56U);
    t19 = *((char **)t13);
    memset(t28, 0, 8);
    t20 = (t28 + 4);
    t24 = (t19 + 4);
    t48 = *((unsigned int *)t19);
    t49 = (t48 >> 0);
    *((unsigned int *)t28) = t49;
    t50 = *((unsigned int *)t24);
    t51 = (t50 >> 0);
    *((unsigned int *)t20) = t51;
    t52 = *((unsigned int *)t28);
    *((unsigned int *)t28) = (t52 & 255U);
    t53 = *((unsigned int *)t20);
    *((unsigned int *)t20) = (t53 & 255U);
    t25 = (t0 + 4072);
    t26 = (t25 + 56U);
    t27 = *((char **)t26);
    memset(t32, 0, 8);
    t29 = (t32 + 4);
    t30 = (t27 + 4);
    t56 = *((unsigned int *)t27);
    t57 = (t56 >> 0);
    *((unsigned int *)t32) = t57;
    t58 = *((unsigned int *)t30);
    t59 = (t58 >> 0);
    *((unsigned int *)t29) = t59;
    t60 = *((unsigned int *)t32);
    *((unsigned int *)t32) = (t60 & 255U);
    t61 = *((unsigned int *)t29);
    *((unsigned int *)t29) = (t61 & 255U);
    xsi_vlogtype_concat(t12, 16, 16, 2U, t32, 8, t28, 8);
    t31 = (t0 + 4232);
    xsi_vlogvar_assign_value(t31, t12, 0, 0, 16);
    goto LAB52;

LAB56:    t9 = (t8 + 4);
    *((unsigned int *)t8) = 1;
    *((unsigned int *)t9) = 1;
    goto LAB57;

LAB58:    xsi_set_current_line(187, ng0);

LAB61:    xsi_set_current_line(188, ng0);
    t11 = ((char*)((ng2)));
    t13 = (t0 + 2632);
    xsi_vlogvar_assign_value(t13, t11, 0, 0, 1);
    xsi_set_current_line(189, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 4072);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 8);
    xsi_set_current_line(190, ng0);
    t2 = (t0 + 4072);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    memset(t12, 0, 8);
    t5 = (t12 + 4);
    t6 = (t4 + 4);
    t14 = *((unsigned int *)t4);
    t15 = (t14 >> 0);
    *((unsigned int *)t12) = t15;
    t16 = *((unsigned int *)t6);
    t17 = (t16 >> 0);
    *((unsigned int *)t5) = t17;
    t18 = *((unsigned int *)t12);
    *((unsigned int *)t12) = (t18 & 255U);
    t21 = *((unsigned int *)t5);
    *((unsigned int *)t5) = (t21 & 255U);
    t7 = (t0 + 4072);
    t9 = (t7 + 56U);
    t10 = *((char **)t9);
    memset(t28, 0, 8);
    t11 = (t28 + 4);
    t13 = (t10 + 4);
    t22 = *((unsigned int *)t10);
    t23 = (t22 >> 0);
    *((unsigned int *)t28) = t23;
    t34 = *((unsigned int *)t13);
    t35 = (t34 >> 0);
    *((unsigned int *)t11) = t35;
    t36 = *((unsigned int *)t28);
    *((unsigned int *)t28) = (t36 & 255U);
    t37 = *((unsigned int *)t11);
    *((unsigned int *)t11) = (t37 & 255U);
    xsi_vlogtype_concat(t8, 16, 16, 2U, t28, 8, t12, 8);
    t19 = (t0 + 4232);
    xsi_vlogvar_assign_value(t19, t8, 0, 0, 16);
    xsi_set_current_line(191, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 4392);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 4);
    goto LAB60;

LAB64:    t9 = (t8 + 4);
    *((unsigned int *)t8) = 1;
    *((unsigned int *)t9) = 1;
    goto LAB65;

LAB66:    xsi_set_current_line(194, ng0);

LAB69:    xsi_set_current_line(195, ng0);
    t11 = (t0 + 4392);
    t13 = (t11 + 56U);
    t19 = *((char **)t13);
    t20 = ((char*)((ng2)));
    memset(t12, 0, 8);
    t24 = (t19 + 4);
    t25 = (t20 + 4);
    t48 = *((unsigned int *)t19);
    t49 = *((unsigned int *)t20);
    t50 = (t48 ^ t49);
    t51 = *((unsigned int *)t24);
    t52 = *((unsigned int *)t25);
    t53 = (t51 ^ t52);
    t56 = (t50 | t53);
    t57 = *((unsigned int *)t24);
    t58 = *((unsigned int *)t25);
    t59 = (t57 | t58);
    t60 = (~(t59));
    t61 = (t56 & t60);
    if (t61 != 0)
        goto LAB73;

LAB70:    if (t59 != 0)
        goto LAB72;

LAB71:    *((unsigned int *)t12) = 1;

LAB73:    t27 = (t12 + 4);
    t62 = *((unsigned int *)t27);
    t63 = (~(t62));
    t66 = *((unsigned int *)t12);
    t67 = (t66 & t63);
    t68 = (t67 != 0);
    if (t68 > 0)
        goto LAB74;

LAB75:
LAB76:    xsi_set_current_line(199, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 2632);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(200, ng0);
    t2 = (t0 + 4392);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng18)));
    memset(t8, 0, 8);
    t6 = (t4 + 4);
    t7 = (t5 + 4);
    t14 = *((unsigned int *)t4);
    t15 = *((unsigned int *)t5);
    t16 = (t14 ^ t15);
    t17 = *((unsigned int *)t6);
    t18 = *((unsigned int *)t7);
    t21 = (t17 ^ t18);
    t22 = (t16 | t21);
    t23 = *((unsigned int *)t6);
    t34 = *((unsigned int *)t7);
    t35 = (t23 | t34);
    t36 = (~(t35));
    t37 = (t22 & t36);
    if (t37 != 0)
        goto LAB81;

LAB78:    if (t35 != 0)
        goto LAB80;

LAB79:    *((unsigned int *)t8) = 1;

LAB81:    t10 = (t8 + 4);
    t38 = *((unsigned int *)t10);
    t41 = (~(t38));
    t42 = *((unsigned int *)t8);
    t43 = (t42 & t41);
    t47 = (t43 != 0);
    if (t47 > 0)
        goto LAB82;

LAB83:    xsi_set_current_line(205, ng0);

LAB86:    xsi_set_current_line(206, ng0);
    t2 = (t0 + 2792);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng1)));
    memset(t8, 0, 8);
    t6 = (t4 + 4);
    t7 = (t5 + 4);
    t14 = *((unsigned int *)t4);
    t15 = *((unsigned int *)t5);
    t16 = (t14 ^ t15);
    t17 = *((unsigned int *)t6);
    t18 = *((unsigned int *)t7);
    t21 = (t17 ^ t18);
    t22 = (t16 | t21);
    t23 = *((unsigned int *)t6);
    t34 = *((unsigned int *)t7);
    t35 = (t23 | t34);
    t36 = (~(t35));
    t37 = (t22 & t36);
    if (t37 != 0)
        goto LAB90;

LAB87:    if (t35 != 0)
        goto LAB89;

LAB88:    *((unsigned int *)t8) = 1;

LAB90:    t10 = (t8 + 4);
    t38 = *((unsigned int *)t10);
    t41 = (~(t38));
    t42 = *((unsigned int *)t8);
    t43 = (t42 & t41);
    t47 = (t43 != 0);
    if (t47 > 0)
        goto LAB91;

LAB92:
LAB93:
LAB84:    goto LAB68;

LAB72:    t26 = (t12 + 4);
    *((unsigned int *)t12) = 1;
    *((unsigned int *)t26) = 1;
    goto LAB73;

LAB74:    xsi_set_current_line(196, ng0);

LAB77:    xsi_set_current_line(197, ng0);
    t29 = (t0 + 4072);
    t30 = (t29 + 56U);
    t31 = *((char **)t30);
    memset(t32, 0, 8);
    t33 = (t32 + 4);
    t39 = (t31 + 4);
    t69 = *((unsigned int *)t31);
    t70 = (t69 >> 0);
    *((unsigned int *)t32) = t70;
    t71 = *((unsigned int *)t39);
    t73 = (t71 >> 0);
    *((unsigned int *)t33) = t73;
    t74 = *((unsigned int *)t32);
    *((unsigned int *)t32) = (t74 & 255U);
    t75 = *((unsigned int *)t33);
    *((unsigned int *)t33) = (t75 & 255U);
    t44 = ((char*)((ng2)));
    xsi_vlogtype_concat(t28, 16, 16, 2U, t44, 8, t32, 8);
    t45 = (t0 + 4232);
    xsi_vlogvar_assign_value(t45, t28, 0, 0, 16);
    goto LAB76;

LAB80:    t9 = (t8 + 4);
    *((unsigned int *)t8) = 1;
    *((unsigned int *)t9) = 1;
    goto LAB81;

LAB82:    xsi_set_current_line(201, ng0);

LAB85:    xsi_set_current_line(202, ng0);
    t11 = ((char*)((ng3)));
    t13 = (t0 + 2632);
    xsi_vlogvar_assign_value(t13, t11, 0, 0, 1);
    goto LAB84;

LAB89:    t9 = (t8 + 4);
    *((unsigned int *)t8) = 1;
    *((unsigned int *)t9) = 1;
    goto LAB90;

LAB91:    xsi_set_current_line(207, ng0);

LAB94:    xsi_set_current_line(208, ng0);
    t11 = (t0 + 4232);
    t13 = (t11 + 56U);
    t19 = *((char **)t13);
    memset(t28, 0, 8);
    t20 = (t28 + 4);
    t24 = (t19 + 4);
    t48 = *((unsigned int *)t19);
    t49 = (t48 >> 15);
    t50 = (t49 & 1);
    *((unsigned int *)t28) = t50;
    t51 = *((unsigned int *)t24);
    t52 = (t51 >> 15);
    t53 = (t52 & 1);
    *((unsigned int *)t20) = t53;
    t25 = (t0 + 4232);
    t26 = (t25 + 56U);
    t27 = *((char **)t26);
    memset(t32, 0, 8);
    t29 = (t32 + 4);
    t30 = (t27 + 4);
    t56 = *((unsigned int *)t27);
    t57 = (t56 >> 0);
    *((unsigned int *)t32) = t57;
    t58 = *((unsigned int *)t30);
    t59 = (t58 >> 0);
    *((unsigned int *)t29) = t59;
    t60 = *((unsigned int *)t32);
    *((unsigned int *)t32) = (t60 & 32767U);
    t61 = *((unsigned int *)t29);
    *((unsigned int *)t29) = (t61 & 32767U);
    xsi_vlogtype_concat(t12, 16, 16, 2U, t32, 15, t28, 1);
    t31 = (t0 + 4232);
    xsi_vlogvar_assign_value(t31, t12, 0, 0, 16);
    xsi_set_current_line(209, ng0);
    t2 = (t0 + 4392);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng3)));
    memset(t8, 0, 8);
    xsi_vlog_unsigned_add(t8, 4, t4, 4, t5, 4);
    t6 = (t0 + 4392);
    xsi_vlogvar_assign_value(t6, t8, 0, 0, 4);
    goto LAB93;

LAB97:    t9 = (t8 + 4);
    *((unsigned int *)t8) = 1;
    *((unsigned int *)t9) = 1;
    goto LAB98;

LAB99:    xsi_set_current_line(214, ng0);

LAB102:    xsi_set_current_line(215, ng0);
    t11 = ((char*)((ng2)));
    t13 = (t0 + 2632);
    xsi_vlogvar_assign_value(t13, t11, 0, 0, 1);
    goto LAB101;

}

static void Cont_219_9(char *t0)
{
    char t3[8];
    char t4[8];
    char *t1;
    char *t2;
    char *t5;
    char *t6;
    char *t7;
    char *t8;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
    unsigned int t12;
    unsigned int t13;
    unsigned int t14;
    char *t15;
    char *t16;
    char *t17;
    char *t18;
    char *t19;
    unsigned int t20;
    unsigned int t21;
    char *t22;
    unsigned int t23;
    unsigned int t24;
    char *t25;
    unsigned int t26;
    unsigned int t27;
    char *t28;

LAB0:    t1 = (t0 + 7704U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(219, ng0);
    t2 = (t0 + 4232);
    t5 = (t2 + 56U);
    t6 = *((char **)t5);
    memset(t4, 0, 8);
    t7 = (t4 + 4);
    t8 = (t6 + 4);
    t9 = *((unsigned int *)t6);
    t10 = (t9 >> 0);
    *((unsigned int *)t4) = t10;
    t11 = *((unsigned int *)t8);
    t12 = (t11 >> 0);
    *((unsigned int *)t7) = t12;
    t13 = *((unsigned int *)t4);
    *((unsigned int *)t4) = (t13 & 255U);
    t14 = *((unsigned int *)t7);
    *((unsigned int *)t7) = (t14 & 255U);
    xsi_vlogtype_concat(t3, 8, 8, 1U, t4, 8);
    t15 = (t0 + 8312);
    t16 = (t15 + 56U);
    t17 = *((char **)t16);
    t18 = (t17 + 56U);
    t19 = *((char **)t18);
    memset(t19, 0, 8);
    t20 = 255U;
    t21 = t20;
    t22 = (t3 + 4);
    t23 = *((unsigned int *)t3);
    t20 = (t20 & t23);
    t24 = *((unsigned int *)t22);
    t21 = (t21 & t24);
    t25 = (t19 + 4);
    t26 = *((unsigned int *)t19);
    *((unsigned int *)t19) = (t26 | t20);
    t27 = *((unsigned int *)t25);
    *((unsigned int *)t25) = (t27 | t21);
    xsi_driver_vfirst_trans(t15, 0, 7);
    t28 = (t0 + 8168);
    *((int *)t28) = 1;

LAB1:    return;
}


extern void work_m_00000000003989106303_1026299294_init()
{
	static char *pe[] = {(void *)Always_38_0,(void *)Always_48_1,(void *)Always_62_2,(void *)Always_92_3,(void *)Always_144_4,(void *)Always_148_5,(void *)Always_157_6,(void *)Cont_166_7,(void *)Always_173_8,(void *)Cont_219_9};
	xsi_register_didat("work_m_00000000003989106303_1026299294", "isim/button_led_buzzer_isim_beh.exe.sim/work/m_00000000003989106303_1026299294.didat");
	xsi_register_executes(pe);
}
