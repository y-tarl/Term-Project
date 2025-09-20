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
static const char *ng0 = "C:/Users/Lenovo/Desktop/Summator/button_led_buzzer.v";
static unsigned int ng1[] = {100000U, 0U};
static unsigned int ng2[] = {0U, 0U};
static unsigned int ng3[] = {1U, 0U};
static unsigned int ng4[] = {3U, 0U};
static unsigned int ng5[] = {2U, 0U};
static unsigned int ng6[] = {14U, 0U};
static unsigned int ng7[] = {13U, 0U};
static unsigned int ng8[] = {5U, 0U};
static unsigned int ng9[] = {11U, 0U};
static unsigned int ng10[] = {9U, 0U};
static unsigned int ng11[] = {7U, 0U};
static unsigned int ng12[] = {15U, 0U};
static unsigned int ng13[] = {17U, 0U};
static unsigned int ng14[] = {6U, 0U};
static unsigned int ng15[] = {10U, 0U};
static unsigned int ng16[] = {4U, 0U};
static unsigned int ng17[] = {8U, 0U};
static unsigned int ng18[] = {12U, 0U};
static unsigned int ng19[] = {16U, 0U};
static unsigned int ng20[] = {60000U, 0U};
static unsigned int ng21[] = {20000U, 0U};
static int ng22[] = {1, 0};
static int ng23[] = {0, 0};



static void Always_42_0(char *t0)
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

LAB2:    xsi_set_current_line(42, ng0);
    t2 = (t0 + 7776);
    *((int *)t2) = 1;
    t3 = (t0 + 5504);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(43, ng0);
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

LAB10:    xsi_set_current_line(49, ng0);

LAB13:    xsi_set_current_line(50, ng0);
    t2 = (t0 + 2792);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng3)));
    memset(t8, 0, 8);
    xsi_vlog_unsigned_add(t8, 17, t4, 17, t5, 17);
    t6 = (t0 + 2792);
    xsi_vlogvar_wait_assign_value(t6, t8, 0, 0, 17, 0LL);
    xsi_set_current_line(51, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 2952);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 1, 0LL);

LAB11:    goto LAB2;

LAB7:    t23 = (t8 + 4);
    *((unsigned int *)t8) = 1;
    *((unsigned int *)t23) = 1;
    goto LAB8;

LAB9:    xsi_set_current_line(44, ng0);

LAB12:    xsi_set_current_line(45, ng0);
    t30 = ((char*)((ng2)));
    t31 = (t0 + 2792);
    xsi_vlogvar_wait_assign_value(t31, t30, 0, 0, 17, 0LL);
    xsi_set_current_line(46, ng0);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 2952);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 1, 0LL);
    goto LAB11;

}

static void Always_56_1(char *t0)
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

LAB0:    t1 = (t0 + 5720U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(56, ng0);
    t2 = (t0 + 7792);
    *((int *)t2) = 1;
    t3 = (t0 + 5752);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(57, ng0);

LAB5:    xsi_set_current_line(58, ng0);
    t4 = (t0 + 3112);
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

LAB10:    t2 = ((char*)((ng4)));
    t8 = xsi_vlog_unsigned_case_compare(t6, 3, t2, 3);
    if (t8 == 1)
        goto LAB11;

LAB12:    t2 = ((char*)((ng5)));
    t8 = xsi_vlog_unsigned_case_compare(t6, 3, t2, 3);
    if (t8 == 1)
        goto LAB13;

LAB14:
LAB16:
LAB15:    xsi_set_current_line(80, ng0);
    t2 = (t0 + 3112);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 3112);
    xsi_vlogvar_wait_assign_value(t5, t4, 0, 0, 3, 0LL);

LAB17:    goto LAB2;

LAB7:    xsi_set_current_line(60, ng0);
    t9 = (t0 + 2952);
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

LAB19:    xsi_set_current_line(63, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 3112);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 3, 0LL);

LAB20:    goto LAB17;

LAB9:    xsi_set_current_line(65, ng0);
    t3 = (t0 + 2952);
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

LAB22:    xsi_set_current_line(68, ng0);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 3112);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 3, 0LL);

LAB23:    goto LAB17;

LAB11:    xsi_set_current_line(70, ng0);
    t3 = (t0 + 2952);
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

LAB25:    xsi_set_current_line(73, ng0);
    t2 = ((char*)((ng4)));
    t3 = (t0 + 3112);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 3, 0LL);

LAB26:    goto LAB17;

LAB13:    xsi_set_current_line(75, ng0);
    t3 = (t0 + 2952);
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

LAB28:    xsi_set_current_line(78, ng0);
    t2 = ((char*)((ng5)));
    t3 = (t0 + 3112);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 3, 0LL);

LAB29:    goto LAB17;

LAB18:    xsi_set_current_line(61, ng0);
    t18 = ((char*)((ng3)));
    t19 = (t0 + 3112);
    xsi_vlogvar_wait_assign_value(t19, t18, 0, 0, 3, 0LL);
    goto LAB20;

LAB21:    xsi_set_current_line(66, ng0);
    t9 = ((char*)((ng4)));
    t10 = (t0 + 3112);
    xsi_vlogvar_wait_assign_value(t10, t9, 0, 0, 3, 0LL);
    goto LAB23;

LAB24:    xsi_set_current_line(71, ng0);
    t9 = ((char*)((ng5)));
    t10 = (t0 + 3112);
    xsi_vlogvar_wait_assign_value(t10, t9, 0, 0, 3, 0LL);
    goto LAB26;

LAB27:    xsi_set_current_line(76, ng0);
    t9 = ((char*)((ng2)));
    t10 = (t0 + 3112);
    xsi_vlogvar_wait_assign_value(t10, t9, 0, 0, 3, 0LL);
    goto LAB29;

}

static void Always_86_2(char *t0)
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

LAB0:    t1 = (t0 + 5968U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(86, ng0);
    t2 = (t0 + 7808);
    *((int *)t2) = 1;
    t3 = (t0 + 6000);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(87, ng0);

LAB5:    xsi_set_current_line(88, ng0);
    t4 = (t0 + 3112);
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

LAB10:    t2 = ((char*)((ng4)));
    t8 = xsi_vlog_unsigned_case_compare(t6, 3, t2, 3);
    if (t8 == 1)
        goto LAB11;

LAB12:    t2 = ((char*)((ng5)));
    t8 = xsi_vlog_unsigned_case_compare(t6, 3, t2, 3);
    if (t8 == 1)
        goto LAB13;

LAB14:
LAB16:
LAB15:    xsi_set_current_line(138, ng0);

LAB74:    xsi_set_current_line(139, ng0);
    t2 = ((char*)((ng12)));
    t9 = (t0 + 2472);
    xsi_vlogvar_wait_assign_value(t9, t2, 0, 0, 4, 0LL);
    xsi_set_current_line(140, ng0);
    t2 = ((char*)((ng13)));
    t9 = (t0 + 3272);
    xsi_vlogvar_wait_assign_value(t9, t2, 0, 0, 5, 0LL);

LAB17:    goto LAB2;

LAB7:    xsi_set_current_line(89, ng0);

LAB18:    xsi_set_current_line(90, ng0);
    t9 = ((char*)((ng6)));
    t10 = (t0 + 2472);
    xsi_vlogvar_wait_assign_value(t10, t9, 0, 0, 4, 0LL);
    xsi_set_current_line(91, ng0);
    t2 = (t0 + 1752U);
    t3 = *((char **)t2);

LAB19:    t2 = ((char*)((ng6)));
    t8 = xsi_vlog_unsigned_case_compare(t3, 4, t2, 4);
    if (t8 == 1)
        goto LAB20;

LAB21:    t2 = ((char*)((ng7)));
    t8 = xsi_vlog_unsigned_case_compare(t3, 4, t2, 4);
    if (t8 == 1)
        goto LAB22;

LAB23:    t2 = ((char*)((ng9)));
    t8 = xsi_vlog_unsigned_case_compare(t3, 4, t2, 4);
    if (t8 == 1)
        goto LAB24;

LAB25:    t2 = ((char*)((ng11)));
    t8 = xsi_vlog_unsigned_case_compare(t3, 4, t2, 4);
    if (t8 == 1)
        goto LAB26;

LAB27:    t2 = ((char*)((ng12)));
    t8 = xsi_vlog_unsigned_case_compare(t3, 4, t2, 4);
    if (t8 == 1)
        goto LAB28;

LAB29:
LAB30:    goto LAB17;

LAB9:    xsi_set_current_line(101, ng0);

LAB32:    xsi_set_current_line(102, ng0);
    t4 = ((char*)((ng7)));
    t5 = (t0 + 2472);
    xsi_vlogvar_wait_assign_value(t5, t4, 0, 0, 4, 0LL);
    xsi_set_current_line(103, ng0);
    t2 = (t0 + 1752U);
    t4 = *((char **)t2);

LAB33:    t2 = ((char*)((ng6)));
    t8 = xsi_vlog_unsigned_case_compare(t4, 4, t2, 4);
    if (t8 == 1)
        goto LAB34;

LAB35:    t2 = ((char*)((ng7)));
    t8 = xsi_vlog_unsigned_case_compare(t4, 4, t2, 4);
    if (t8 == 1)
        goto LAB36;

LAB37:    t2 = ((char*)((ng9)));
    t8 = xsi_vlog_unsigned_case_compare(t4, 4, t2, 4);
    if (t8 == 1)
        goto LAB38;

LAB39:    t2 = ((char*)((ng11)));
    t8 = xsi_vlog_unsigned_case_compare(t4, 4, t2, 4);
    if (t8 == 1)
        goto LAB40;

LAB41:    t2 = ((char*)((ng12)));
    t8 = xsi_vlog_unsigned_case_compare(t4, 4, t2, 4);
    if (t8 == 1)
        goto LAB42;

LAB43:
LAB44:    goto LAB17;

LAB11:    xsi_set_current_line(114, ng0);

LAB46:    xsi_set_current_line(115, ng0);
    t5 = ((char*)((ng9)));
    t7 = (t0 + 2472);
    xsi_vlogvar_wait_assign_value(t7, t5, 0, 0, 4, 0LL);
    xsi_set_current_line(116, ng0);
    t2 = (t0 + 1752U);
    t5 = *((char **)t2);

LAB47:    t2 = ((char*)((ng6)));
    t8 = xsi_vlog_unsigned_case_compare(t5, 4, t2, 4);
    if (t8 == 1)
        goto LAB48;

LAB49:    t2 = ((char*)((ng7)));
    t8 = xsi_vlog_unsigned_case_compare(t5, 4, t2, 4);
    if (t8 == 1)
        goto LAB50;

LAB51:    t2 = ((char*)((ng9)));
    t8 = xsi_vlog_unsigned_case_compare(t5, 4, t2, 4);
    if (t8 == 1)
        goto LAB52;

LAB53:    t2 = ((char*)((ng11)));
    t8 = xsi_vlog_unsigned_case_compare(t5, 4, t2, 4);
    if (t8 == 1)
        goto LAB54;

LAB55:    t2 = ((char*)((ng12)));
    t8 = xsi_vlog_unsigned_case_compare(t5, 4, t2, 4);
    if (t8 == 1)
        goto LAB56;

LAB57:
LAB58:    goto LAB17;

LAB13:    xsi_set_current_line(126, ng0);

LAB60:    xsi_set_current_line(127, ng0);
    t7 = ((char*)((ng11)));
    t9 = (t0 + 2472);
    xsi_vlogvar_wait_assign_value(t9, t7, 0, 0, 4, 0LL);
    xsi_set_current_line(128, ng0);
    t2 = (t0 + 1752U);
    t7 = *((char **)t2);

LAB61:    t2 = ((char*)((ng6)));
    t8 = xsi_vlog_unsigned_case_compare(t7, 4, t2, 4);
    if (t8 == 1)
        goto LAB62;

LAB63:    t2 = ((char*)((ng7)));
    t8 = xsi_vlog_unsigned_case_compare(t7, 4, t2, 4);
    if (t8 == 1)
        goto LAB64;

LAB65:    t2 = ((char*)((ng9)));
    t8 = xsi_vlog_unsigned_case_compare(t7, 4, t2, 4);
    if (t8 == 1)
        goto LAB66;

LAB67:    t2 = ((char*)((ng11)));
    t8 = xsi_vlog_unsigned_case_compare(t7, 4, t2, 4);
    if (t8 == 1)
        goto LAB68;

LAB69:    t2 = ((char*)((ng12)));
    t8 = xsi_vlog_unsigned_case_compare(t7, 4, t2, 4);
    if (t8 == 1)
        goto LAB70;

LAB71:
LAB72:    goto LAB17;

LAB20:    xsi_set_current_line(92, ng0);
    t4 = ((char*)((ng3)));
    t5 = (t0 + 3272);
    xsi_vlogvar_wait_assign_value(t5, t4, 0, 0, 5, 0LL);
    goto LAB30;

LAB22:    xsi_set_current_line(93, ng0);
    t4 = ((char*)((ng8)));
    t5 = (t0 + 3272);
    xsi_vlogvar_wait_assign_value(t5, t4, 0, 0, 5, 0LL);
    goto LAB30;

LAB24:    xsi_set_current_line(94, ng0);
    t4 = ((char*)((ng10)));
    t5 = (t0 + 3272);
    xsi_vlogvar_wait_assign_value(t5, t4, 0, 0, 5, 0LL);
    goto LAB30;

LAB26:    xsi_set_current_line(95, ng0);
    t4 = ((char*)((ng7)));
    t5 = (t0 + 3272);
    xsi_vlogvar_wait_assign_value(t5, t4, 0, 0, 5, 0LL);
    goto LAB30;

LAB28:    xsi_set_current_line(96, ng0);

LAB31:    xsi_set_current_line(96, ng0);
    t4 = ((char*)((ng13)));
    t5 = (t0 + 3272);
    xsi_vlogvar_wait_assign_value(t5, t4, 0, 0, 5, 0LL);
    goto LAB30;

LAB34:    xsi_set_current_line(104, ng0);
    t5 = ((char*)((ng5)));
    t7 = (t0 + 3272);
    xsi_vlogvar_wait_assign_value(t7, t5, 0, 0, 5, 0LL);
    goto LAB44;

LAB36:    xsi_set_current_line(105, ng0);
    t5 = ((char*)((ng14)));
    t7 = (t0 + 3272);
    xsi_vlogvar_wait_assign_value(t7, t5, 0, 0, 5, 0LL);
    goto LAB44;

LAB38:    xsi_set_current_line(106, ng0);
    t5 = ((char*)((ng15)));
    t7 = (t0 + 3272);
    xsi_vlogvar_wait_assign_value(t7, t5, 0, 0, 5, 0LL);
    goto LAB44;

LAB40:    xsi_set_current_line(107, ng0);
    t5 = ((char*)((ng6)));
    t7 = (t0 + 3272);
    xsi_vlogvar_wait_assign_value(t7, t5, 0, 0, 5, 0LL);
    goto LAB44;

LAB42:    xsi_set_current_line(108, ng0);

LAB45:    xsi_set_current_line(108, ng0);
    t5 = ((char*)((ng13)));
    t7 = (t0 + 3272);
    xsi_vlogvar_wait_assign_value(t7, t5, 0, 0, 5, 0LL);
    goto LAB44;

LAB48:    xsi_set_current_line(117, ng0);
    t7 = ((char*)((ng4)));
    t9 = (t0 + 3272);
    xsi_vlogvar_wait_assign_value(t9, t7, 0, 0, 5, 0LL);
    goto LAB58;

LAB50:    xsi_set_current_line(118, ng0);
    t7 = ((char*)((ng11)));
    t9 = (t0 + 3272);
    xsi_vlogvar_wait_assign_value(t9, t7, 0, 0, 5, 0LL);
    goto LAB58;

LAB52:    xsi_set_current_line(119, ng0);
    t7 = ((char*)((ng9)));
    t9 = (t0 + 3272);
    xsi_vlogvar_wait_assign_value(t9, t7, 0, 0, 5, 0LL);
    goto LAB58;

LAB54:    xsi_set_current_line(120, ng0);
    t7 = ((char*)((ng12)));
    t9 = (t0 + 3272);
    xsi_vlogvar_wait_assign_value(t9, t7, 0, 0, 5, 0LL);
    goto LAB58;

LAB56:    xsi_set_current_line(121, ng0);

LAB59:    xsi_set_current_line(121, ng0);
    t7 = ((char*)((ng13)));
    t9 = (t0 + 3272);
    xsi_vlogvar_wait_assign_value(t9, t7, 0, 0, 5, 0LL);
    goto LAB58;

LAB62:    xsi_set_current_line(129, ng0);
    t9 = ((char*)((ng16)));
    t10 = (t0 + 3272);
    xsi_vlogvar_wait_assign_value(t10, t9, 0, 0, 5, 0LL);
    goto LAB72;

LAB64:    xsi_set_current_line(130, ng0);
    t9 = ((char*)((ng17)));
    t10 = (t0 + 3272);
    xsi_vlogvar_wait_assign_value(t10, t9, 0, 0, 5, 0LL);
    goto LAB72;

LAB66:    xsi_set_current_line(131, ng0);
    t9 = ((char*)((ng18)));
    t10 = (t0 + 3272);
    xsi_vlogvar_wait_assign_value(t10, t9, 0, 0, 5, 0LL);
    goto LAB72;

LAB68:    xsi_set_current_line(132, ng0);
    t9 = ((char*)((ng19)));
    t10 = (t0 + 3272);
    xsi_vlogvar_wait_assign_value(t10, t9, 0, 0, 5, 0LL);
    goto LAB72;

LAB70:    xsi_set_current_line(133, ng0);

LAB73:    xsi_set_current_line(133, ng0);
    t9 = ((char*)((ng13)));
    t10 = (t0 + 3272);
    xsi_vlogvar_wait_assign_value(t10, t9, 0, 0, 5, 0LL);
    goto LAB72;

}

static void Always_150_3(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;

LAB0:    t1 = (t0 + 6216U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(150, ng0);
    t2 = (t0 + 7824);
    *((int *)t2) = 1;
    t3 = (t0 + 6248);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(151, ng0);

LAB5:    xsi_set_current_line(152, ng0);
    t4 = (t0 + 3272);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = (t0 + 3432);
    xsi_vlogvar_wait_assign_value(t7, t6, 0, 0, 5, 0LL);
    goto LAB2;

}

static void Always_156_4(char *t0)
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

LAB0:    t1 = (t0 + 6464U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(156, ng0);
    t2 = (t0 + 7840);
    *((int *)t2) = 1;
    t3 = (t0 + 6496);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(157, ng0);
    t4 = (t0 + 3752);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = ((char*)((ng20)));
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

LAB10:    xsi_set_current_line(159, ng0);
    t2 = (t0 + 3432);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 3272);
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

LAB17:    xsi_set_current_line(161, ng0);
    t2 = (t0 + 3432);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 3272);
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

LAB9:    xsi_set_current_line(158, ng0);
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

LAB16:    xsi_set_current_line(160, ng0);
    t30 = ((char*)((ng2)));
    t31 = (t0 + 3752);
    xsi_vlogvar_wait_assign_value(t31, t30, 0, 0, 20, 0LL);
    goto LAB18;

LAB21:    t23 = (t8 + 4);
    *((unsigned int *)t8) = 1;
    *((unsigned int *)t23) = 1;
    goto LAB22;

LAB23:    xsi_set_current_line(162, ng0);
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

static void Always_170_5(char *t0)
{
    char t8[8];
    char t12[8];
    char t28[8];
    char t44[8];
    char t52[8];
    char t94[8];
    char t96[8];
    char t112[8];
    char t128[8];
    char t136[8];
    char t189[8];
    char t202[8];
    char t217[8];
    char t233[8];
    char t241[8];
    char t273[8];
    char t289[8];
    char t305[8];
    char t313[8];
    char t345[8];
    char t353[8];
    char t393[8];
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
    char *t95;
    char *t97;
    unsigned int t98;
    unsigned int t99;
    unsigned int t100;
    unsigned int t101;
    unsigned int t102;
    char *t103;
    char *t104;
    unsigned int t105;
    unsigned int t106;
    unsigned int t107;
    char *t108;
    char *t109;
    char *t110;
    char *t111;
    char *t113;
    char *t114;
    unsigned int t115;
    unsigned int t116;
    unsigned int t117;
    unsigned int t118;
    unsigned int t119;
    unsigned int t120;
    unsigned int t121;
    unsigned int t122;
    unsigned int t123;
    unsigned int t124;
    unsigned int t125;
    unsigned int t126;
    char *t127;
    char *t129;
    unsigned int t130;
    unsigned int t131;
    unsigned int t132;
    unsigned int t133;
    unsigned int t134;
    char *t135;
    unsigned int t137;
    unsigned int t138;
    unsigned int t139;
    char *t140;
    char *t141;
    char *t142;
    unsigned int t143;
    unsigned int t144;
    unsigned int t145;
    unsigned int t146;
    unsigned int t147;
    unsigned int t148;
    unsigned int t149;
    char *t150;
    char *t151;
    unsigned int t152;
    unsigned int t153;
    unsigned int t154;
    unsigned int t155;
    unsigned int t156;
    unsigned int t157;
    unsigned int t158;
    unsigned int t159;
    int t160;
    int t161;
    unsigned int t162;
    unsigned int t163;
    unsigned int t164;
    unsigned int t165;
    unsigned int t166;
    unsigned int t167;
    char *t168;
    unsigned int t169;
    unsigned int t170;
    unsigned int t171;
    unsigned int t172;
    unsigned int t173;
    char *t174;
    char *t175;
    char *t176;
    char *t177;
    unsigned int t178;
    unsigned int t179;
    unsigned int t180;
    unsigned int t181;
    unsigned int t182;
    unsigned int t183;
    unsigned int t184;
    unsigned int t185;
    unsigned int t186;
    unsigned int t187;
    unsigned int t188;
    unsigned int t190;
    unsigned int t191;
    unsigned int t192;
    unsigned int t193;
    unsigned int t194;
    unsigned int t195;
    unsigned int t196;
    unsigned int t197;
    unsigned int t198;
    unsigned int t199;
    unsigned int t200;
    unsigned int t201;
    unsigned int t203;
    unsigned int t204;
    unsigned int t205;
    unsigned int t206;
    unsigned int t207;
    char *t208;
    char *t209;
    unsigned int t210;
    unsigned int t211;
    unsigned int t212;
    char *t213;
    char *t214;
    char *t215;
    char *t216;
    char *t218;
    char *t219;
    unsigned int t220;
    unsigned int t221;
    unsigned int t222;
    unsigned int t223;
    unsigned int t224;
    unsigned int t225;
    unsigned int t226;
    unsigned int t227;
    unsigned int t228;
    unsigned int t229;
    unsigned int t230;
    unsigned int t231;
    char *t232;
    char *t234;
    unsigned int t235;
    unsigned int t236;
    unsigned int t237;
    unsigned int t238;
    unsigned int t239;
    char *t240;
    unsigned int t242;
    unsigned int t243;
    unsigned int t244;
    char *t245;
    char *t246;
    char *t247;
    unsigned int t248;
    unsigned int t249;
    unsigned int t250;
    unsigned int t251;
    unsigned int t252;
    unsigned int t253;
    unsigned int t254;
    char *t255;
    char *t256;
    unsigned int t257;
    unsigned int t258;
    unsigned int t259;
    unsigned int t260;
    unsigned int t261;
    unsigned int t262;
    unsigned int t263;
    unsigned int t264;
    int t265;
    int t266;
    unsigned int t267;
    unsigned int t268;
    unsigned int t269;
    unsigned int t270;
    unsigned int t271;
    unsigned int t272;
    char *t274;
    unsigned int t275;
    unsigned int t276;
    unsigned int t277;
    unsigned int t278;
    unsigned int t279;
    char *t280;
    char *t281;
    unsigned int t282;
    unsigned int t283;
    unsigned int t284;
    char *t285;
    char *t286;
    char *t287;
    char *t288;
    char *t290;
    char *t291;
    unsigned int t292;
    unsigned int t293;
    unsigned int t294;
    unsigned int t295;
    unsigned int t296;
    unsigned int t297;
    unsigned int t298;
    unsigned int t299;
    unsigned int t300;
    unsigned int t301;
    unsigned int t302;
    unsigned int t303;
    char *t304;
    char *t306;
    unsigned int t307;
    unsigned int t308;
    unsigned int t309;
    unsigned int t310;
    unsigned int t311;
    char *t312;
    unsigned int t314;
    unsigned int t315;
    unsigned int t316;
    char *t317;
    char *t318;
    char *t319;
    unsigned int t320;
    unsigned int t321;
    unsigned int t322;
    unsigned int t323;
    unsigned int t324;
    unsigned int t325;
    unsigned int t326;
    char *t327;
    char *t328;
    unsigned int t329;
    unsigned int t330;
    unsigned int t331;
    unsigned int t332;
    unsigned int t333;
    unsigned int t334;
    unsigned int t335;
    unsigned int t336;
    int t337;
    int t338;
    unsigned int t339;
    unsigned int t340;
    unsigned int t341;
    unsigned int t342;
    unsigned int t343;
    unsigned int t344;
    char *t346;
    unsigned int t347;
    unsigned int t348;
    unsigned int t349;
    unsigned int t350;
    unsigned int t351;
    char *t352;
    unsigned int t354;
    unsigned int t355;
    unsigned int t356;
    char *t357;
    char *t358;
    char *t359;
    unsigned int t360;
    unsigned int t361;
    unsigned int t362;
    unsigned int t363;
    unsigned int t364;
    unsigned int t365;
    unsigned int t366;
    char *t367;
    char *t368;
    unsigned int t369;
    unsigned int t370;
    unsigned int t371;
    int t372;
    unsigned int t373;
    unsigned int t374;
    unsigned int t375;
    int t376;
    unsigned int t377;
    unsigned int t378;
    unsigned int t379;
    unsigned int t380;
    char *t381;
    unsigned int t382;
    unsigned int t383;
    unsigned int t384;
    unsigned int t385;
    unsigned int t386;
    char *t387;
    char *t388;
    char *t389;
    char *t390;
    char *t391;
    char *t392;
    char *t394;

LAB0:    t1 = (t0 + 6712U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(170, ng0);
    t2 = (t0 + 7856);
    *((int *)t2) = 1;
    t3 = (t0 + 6744);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(171, ng0);

LAB5:    xsi_set_current_line(172, ng0);
    t4 = (t0 + 3752);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = ((char*)((ng21)));
    memset(t8, 0, 8);
    t9 = (t6 + 4);
    if (*((unsigned int *)t9) != 0)
        goto LAB7;

LAB6:    t10 = (t7 + 4);
    if (*((unsigned int *)t10) != 0)
        goto LAB7;

LAB10:    if (*((unsigned int *)t6) < *((unsigned int *)t7))
        goto LAB9;

LAB8:    *((unsigned int *)t8) = 1;

LAB9:    memset(t12, 0, 8);
    t13 = (t8 + 4);
    t14 = *((unsigned int *)t13);
    t15 = (~(t14));
    t16 = *((unsigned int *)t8);
    t17 = (t16 & t15);
    t18 = (t17 & 1U);
    if (t18 != 0)
        goto LAB11;

LAB12:    if (*((unsigned int *)t13) != 0)
        goto LAB13;

LAB14:    t20 = (t12 + 4);
    t21 = *((unsigned int *)t12);
    t22 = *((unsigned int *)t20);
    t23 = (t21 || t22);
    if (t23 > 0)
        goto LAB15;

LAB16:    memcpy(t52, t12, 8);

LAB17:    t84 = (t52 + 4);
    t85 = *((unsigned int *)t84);
    t86 = (~(t85));
    t87 = *((unsigned int *)t52);
    t88 = (t87 & t86);
    t89 = (t88 != 0);
    if (t89 > 0)
        goto LAB29;

LAB30:    xsi_set_current_line(177, ng0);

LAB33:    xsi_set_current_line(178, ng0);
    t2 = (t0 + 3912);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 3912);
    xsi_vlogvar_wait_assign_value(t5, t4, 0, 0, 5, 0LL);

LAB31:    xsi_set_current_line(182, ng0);
    t2 = (t0 + 3912);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng3)));
    memset(t8, 0, 8);
    t6 = (t4 + 4);
    if (*((unsigned int *)t6) != 0)
        goto LAB35;

LAB34:    t7 = (t5 + 4);
    if (*((unsigned int *)t7) != 0)
        goto LAB35;

LAB38:    if (*((unsigned int *)t4) < *((unsigned int *)t5))
        goto LAB37;

LAB36:    *((unsigned int *)t8) = 1;

LAB37:    memset(t12, 0, 8);
    t10 = (t8 + 4);
    t14 = *((unsigned int *)t10);
    t15 = (~(t14));
    t16 = *((unsigned int *)t8);
    t17 = (t16 & t15);
    t18 = (t17 & 1U);
    if (t18 != 0)
        goto LAB39;

LAB40:    if (*((unsigned int *)t10) != 0)
        goto LAB41;

LAB42:    t13 = (t12 + 4);
    t21 = *((unsigned int *)t12);
    t22 = *((unsigned int *)t13);
    t23 = (t21 || t22);
    if (t23 > 0)
        goto LAB43;

LAB44:    memcpy(t52, t12, 8);

LAB45:    t66 = (t52 + 4);
    t70 = *((unsigned int *)t66);
    t71 = (~(t70));
    t72 = *((unsigned int *)t52);
    t73 = (t72 & t71);
    t74 = (t73 != 0);
    if (t74 > 0)
        goto LAB58;

LAB59:    xsi_set_current_line(200, ng0);
    t2 = (t0 + 3912);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng6)));
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
    t31 = *((unsigned int *)t7);
    t32 = (t23 | t31);
    t33 = (~(t32));
    t34 = (t22 & t33);
    if (t34 != 0)
        goto LAB190;

LAB187:    if (t32 != 0)
        goto LAB189;

LAB188:    *((unsigned int *)t8) = 1;

LAB190:    t10 = (t8 + 4);
    t35 = *((unsigned int *)t10);
    t36 = (~(t35));
    t37 = *((unsigned int *)t8);
    t38 = (t37 & t36);
    t39 = (t38 != 0);
    if (t39 > 0)
        goto LAB191;

LAB192:    xsi_set_current_line(208, ng0);
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
    t31 = *((unsigned int *)t7);
    t32 = (t23 | t31);
    t33 = (~(t32));
    t34 = (t22 & t33);
    if (t34 != 0)
        goto LAB198;

LAB195:    if (t32 != 0)
        goto LAB197;

LAB196:    *((unsigned int *)t8) = 1;

LAB198:    t10 = (t8 + 4);
    t35 = *((unsigned int *)t10);
    t36 = (~(t35));
    t37 = *((unsigned int *)t8);
    t38 = (t37 & t36);
    t39 = (t38 != 0);
    if (t39 > 0)
        goto LAB199;

LAB200:
LAB201:
LAB193:
LAB60:    goto LAB2;

LAB7:    t11 = (t8 + 4);
    *((unsigned int *)t8) = 1;
    *((unsigned int *)t11) = 1;
    goto LAB9;

LAB11:    *((unsigned int *)t12) = 1;
    goto LAB14;

LAB13:    t19 = (t12 + 4);
    *((unsigned int *)t12) = 1;
    *((unsigned int *)t19) = 1;
    goto LAB14;

LAB15:    t24 = (t0 + 3432);
    t25 = (t24 + 56U);
    t26 = *((char **)t25);
    t27 = ((char*)((ng13)));
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
        goto LAB19;

LAB18:    if (t40 != 0)
        goto LAB20;

LAB21:    memset(t44, 0, 8);
    t45 = (t28 + 4);
    t46 = *((unsigned int *)t45);
    t47 = (~(t46));
    t48 = *((unsigned int *)t28);
    t49 = (t48 & t47);
    t50 = (t49 & 1U);
    if (t50 != 0)
        goto LAB22;

LAB23:    if (*((unsigned int *)t45) != 0)
        goto LAB24;

LAB25:    t53 = *((unsigned int *)t12);
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
        goto LAB26;

LAB27:
LAB28:    goto LAB17;

LAB19:    *((unsigned int *)t28) = 1;
    goto LAB21;

LAB20:    t43 = (t28 + 4);
    *((unsigned int *)t28) = 1;
    *((unsigned int *)t43) = 1;
    goto LAB21;

LAB22:    *((unsigned int *)t44) = 1;
    goto LAB25;

LAB24:    t51 = (t44 + 4);
    *((unsigned int *)t44) = 1;
    *((unsigned int *)t51) = 1;
    goto LAB25;

LAB26:    t64 = *((unsigned int *)t52);
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
    goto LAB28;

LAB29:    xsi_set_current_line(173, ng0);

LAB32:    xsi_set_current_line(174, ng0);
    t90 = (t0 + 3432);
    t91 = (t90 + 56U);
    t92 = *((char **)t91);
    t93 = (t0 + 3912);
    xsi_vlogvar_wait_assign_value(t93, t92, 0, 0, 5, 0LL);
    goto LAB31;

LAB35:    t9 = (t8 + 4);
    *((unsigned int *)t8) = 1;
    *((unsigned int *)t9) = 1;
    goto LAB37;

LAB39:    *((unsigned int *)t12) = 1;
    goto LAB42;

LAB41:    t11 = (t12 + 4);
    *((unsigned int *)t12) = 1;
    *((unsigned int *)t11) = 1;
    goto LAB42;

LAB43:    t19 = (t0 + 3912);
    t20 = (t19 + 56U);
    t24 = *((char **)t20);
    t25 = ((char*)((ng18)));
    memset(t28, 0, 8);
    t26 = (t24 + 4);
    if (*((unsigned int *)t26) != 0)
        goto LAB47;

LAB46:    t27 = (t25 + 4);
    if (*((unsigned int *)t27) != 0)
        goto LAB47;

LAB50:    if (*((unsigned int *)t24) > *((unsigned int *)t25))
        goto LAB49;

LAB48:    *((unsigned int *)t28) = 1;

LAB49:    memset(t44, 0, 8);
    t30 = (t28 + 4);
    t31 = *((unsigned int *)t30);
    t32 = (~(t31));
    t33 = *((unsigned int *)t28);
    t34 = (t33 & t32);
    t35 = (t34 & 1U);
    if (t35 != 0)
        goto LAB51;

LAB52:    if (*((unsigned int *)t30) != 0)
        goto LAB53;

LAB54:    t36 = *((unsigned int *)t12);
    t37 = *((unsigned int *)t44);
    t38 = (t36 & t37);
    *((unsigned int *)t52) = t38;
    t45 = (t12 + 4);
    t51 = (t44 + 4);
    t56 = (t52 + 4);
    t39 = *((unsigned int *)t45);
    t40 = *((unsigned int *)t51);
    t41 = (t39 | t40);
    *((unsigned int *)t56) = t41;
    t42 = *((unsigned int *)t56);
    t46 = (t42 != 0);
    if (t46 == 1)
        goto LAB55;

LAB56:
LAB57:    goto LAB45;

LAB47:    t29 = (t28 + 4);
    *((unsigned int *)t28) = 1;
    *((unsigned int *)t29) = 1;
    goto LAB49;

LAB51:    *((unsigned int *)t44) = 1;
    goto LAB54;

LAB53:    t43 = (t44 + 4);
    *((unsigned int *)t44) = 1;
    *((unsigned int *)t43) = 1;
    goto LAB54;

LAB55:    t47 = *((unsigned int *)t52);
    t48 = *((unsigned int *)t56);
    *((unsigned int *)t52) = (t47 | t48);
    t57 = (t12 + 4);
    t58 = (t44 + 4);
    t49 = *((unsigned int *)t12);
    t50 = (~(t49));
    t53 = *((unsigned int *)t57);
    t54 = (~(t53));
    t55 = *((unsigned int *)t44);
    t59 = (~(t55));
    t60 = *((unsigned int *)t58);
    t61 = (~(t60));
    t76 = (t50 & t54);
    t77 = (t59 & t61);
    t62 = (~(t76));
    t63 = (~(t77));
    t64 = *((unsigned int *)t56);
    *((unsigned int *)t56) = (t64 & t62);
    t65 = *((unsigned int *)t56);
    *((unsigned int *)t56) = (t65 & t63);
    t68 = *((unsigned int *)t52);
    *((unsigned int *)t52) = (t68 & t62);
    t69 = *((unsigned int *)t52);
    *((unsigned int *)t52) = (t69 & t63);
    goto LAB57;

LAB58:    xsi_set_current_line(183, ng0);

LAB61:    xsi_set_current_line(184, ng0);
    t67 = (t0 + 4072);
    t84 = (t67 + 56U);
    t90 = *((char **)t84);
    t91 = ((char*)((ng2)));
    memset(t94, 0, 8);
    t92 = (t90 + 4);
    t93 = (t91 + 4);
    t75 = *((unsigned int *)t90);
    t78 = *((unsigned int *)t91);
    t79 = (t75 ^ t78);
    t80 = *((unsigned int *)t92);
    t81 = *((unsigned int *)t93);
    t82 = (t80 ^ t81);
    t83 = (t79 | t82);
    t85 = *((unsigned int *)t92);
    t86 = *((unsigned int *)t93);
    t87 = (t85 | t86);
    t88 = (~(t87));
    t89 = (t83 & t88);
    if (t89 != 0)
        goto LAB65;

LAB62:    if (t87 != 0)
        goto LAB64;

LAB63:    *((unsigned int *)t94) = 1;

LAB65:    memset(t96, 0, 8);
    t97 = (t94 + 4);
    t98 = *((unsigned int *)t97);
    t99 = (~(t98));
    t100 = *((unsigned int *)t94);
    t101 = (t100 & t99);
    t102 = (t101 & 1U);
    if (t102 != 0)
        goto LAB66;

LAB67:    if (*((unsigned int *)t97) != 0)
        goto LAB68;

LAB69:    t104 = (t96 + 4);
    t105 = *((unsigned int *)t96);
    t106 = *((unsigned int *)t104);
    t107 = (t105 || t106);
    if (t107 > 0)
        goto LAB70;

LAB71:    memcpy(t136, t96, 8);

LAB72:    t168 = (t136 + 4);
    t169 = *((unsigned int *)t168);
    t170 = (~(t169));
    t171 = *((unsigned int *)t136);
    t172 = (t171 & t170);
    t173 = (t172 != 0);
    if (t173 > 0)
        goto LAB84;

LAB85:    xsi_set_current_line(190, ng0);

LAB88:    xsi_set_current_line(191, ng0);
    t2 = (t0 + 3912);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 4232);
    xsi_vlogvar_assign_value(t5, t4, 0, 0, 5);

LAB86:    xsi_set_current_line(194, ng0);
    t2 = (t0 + 4072);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng2)));
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
    t31 = *((unsigned int *)t7);
    t32 = (t23 | t31);
    t33 = (~(t32));
    t34 = (t22 & t33);
    if (t34 != 0)
        goto LAB90;

LAB89:    if (t32 != 0)
        goto LAB91;

LAB92:    memset(t12, 0, 8);
    t10 = (t8 + 4);
    t35 = *((unsigned int *)t10);
    t36 = (~(t35));
    t37 = *((unsigned int *)t8);
    t38 = (t37 & t36);
    t39 = (t38 & 1U);
    if (t39 != 0)
        goto LAB93;

LAB94:    if (*((unsigned int *)t10) != 0)
        goto LAB95;

LAB96:    t13 = (t12 + 4);
    t40 = *((unsigned int *)t12);
    t41 = *((unsigned int *)t13);
    t42 = (t40 || t41);
    if (t42 > 0)
        goto LAB97;

LAB98:    memcpy(t52, t12, 8);

LAB99:    memset(t94, 0, 8);
    t66 = (t52 + 4);
    t107 = *((unsigned int *)t66);
    t115 = (~(t107));
    t116 = *((unsigned int *)t52);
    t117 = (t116 & t115);
    t118 = (t117 & 1U);
    if (t118 != 0)
        goto LAB111;

LAB112:    if (*((unsigned int *)t66) != 0)
        goto LAB113;

LAB114:    t84 = (t94 + 4);
    t119 = *((unsigned int *)t94);
    t120 = *((unsigned int *)t84);
    t121 = (t119 || t120);
    if (t121 > 0)
        goto LAB115;

LAB116:    memcpy(t128, t94, 8);

LAB117:    memset(t136, 0, 8);
    t135 = (t128 + 4);
    t180 = *((unsigned int *)t135);
    t181 = (~(t180));
    t182 = *((unsigned int *)t128);
    t183 = (t182 & t181);
    t184 = (t183 & 1U);
    if (t184 != 0)
        goto LAB129;

LAB130:    if (*((unsigned int *)t135) != 0)
        goto LAB131;

LAB132:    t141 = (t136 + 4);
    t185 = *((unsigned int *)t136);
    t186 = (!(t185));
    t187 = *((unsigned int *)t141);
    t188 = (t186 || t187);
    if (t188 > 0)
        goto LAB133;

LAB134:    memcpy(t353, t136, 8);

LAB135:    t381 = (t353 + 4);
    t382 = *((unsigned int *)t381);
    t383 = (~(t382));
    t384 = *((unsigned int *)t353);
    t385 = (t384 & t383);
    t386 = (t385 != 0);
    if (t386 > 0)
        goto LAB183;

LAB184:
LAB185:    goto LAB60;

LAB64:    t95 = (t94 + 4);
    *((unsigned int *)t94) = 1;
    *((unsigned int *)t95) = 1;
    goto LAB65;

LAB66:    *((unsigned int *)t96) = 1;
    goto LAB69;

LAB68:    t103 = (t96 + 4);
    *((unsigned int *)t96) = 1;
    *((unsigned int *)t103) = 1;
    goto LAB69;

LAB70:    t108 = (t0 + 3592);
    t109 = (t108 + 56U);
    t110 = *((char **)t109);
    t111 = ((char*)((ng2)));
    memset(t112, 0, 8);
    t113 = (t110 + 4);
    t114 = (t111 + 4);
    t115 = *((unsigned int *)t110);
    t116 = *((unsigned int *)t111);
    t117 = (t115 ^ t116);
    t118 = *((unsigned int *)t113);
    t119 = *((unsigned int *)t114);
    t120 = (t118 ^ t119);
    t121 = (t117 | t120);
    t122 = *((unsigned int *)t113);
    t123 = *((unsigned int *)t114);
    t124 = (t122 | t123);
    t125 = (~(t124));
    t126 = (t121 & t125);
    if (t126 != 0)
        goto LAB76;

LAB73:    if (t124 != 0)
        goto LAB75;

LAB74:    *((unsigned int *)t112) = 1;

LAB76:    memset(t128, 0, 8);
    t129 = (t112 + 4);
    t130 = *((unsigned int *)t129);
    t131 = (~(t130));
    t132 = *((unsigned int *)t112);
    t133 = (t132 & t131);
    t134 = (t133 & 1U);
    if (t134 != 0)
        goto LAB77;

LAB78:    if (*((unsigned int *)t129) != 0)
        goto LAB79;

LAB80:    t137 = *((unsigned int *)t96);
    t138 = *((unsigned int *)t128);
    t139 = (t137 & t138);
    *((unsigned int *)t136) = t139;
    t140 = (t96 + 4);
    t141 = (t128 + 4);
    t142 = (t136 + 4);
    t143 = *((unsigned int *)t140);
    t144 = *((unsigned int *)t141);
    t145 = (t143 | t144);
    *((unsigned int *)t142) = t145;
    t146 = *((unsigned int *)t142);
    t147 = (t146 != 0);
    if (t147 == 1)
        goto LAB81;

LAB82:
LAB83:    goto LAB72;

LAB75:    t127 = (t112 + 4);
    *((unsigned int *)t112) = 1;
    *((unsigned int *)t127) = 1;
    goto LAB76;

LAB77:    *((unsigned int *)t128) = 1;
    goto LAB80;

LAB79:    t135 = (t128 + 4);
    *((unsigned int *)t128) = 1;
    *((unsigned int *)t135) = 1;
    goto LAB80;

LAB81:    t148 = *((unsigned int *)t136);
    t149 = *((unsigned int *)t142);
    *((unsigned int *)t136) = (t148 | t149);
    t150 = (t96 + 4);
    t151 = (t128 + 4);
    t152 = *((unsigned int *)t96);
    t153 = (~(t152));
    t154 = *((unsigned int *)t150);
    t155 = (~(t154));
    t156 = *((unsigned int *)t128);
    t157 = (~(t156));
    t158 = *((unsigned int *)t151);
    t159 = (~(t158));
    t160 = (t153 & t155);
    t161 = (t157 & t159);
    t162 = (~(t160));
    t163 = (~(t161));
    t164 = *((unsigned int *)t142);
    *((unsigned int *)t142) = (t164 & t162);
    t165 = *((unsigned int *)t142);
    *((unsigned int *)t142) = (t165 & t163);
    t166 = *((unsigned int *)t136);
    *((unsigned int *)t136) = (t166 & t162);
    t167 = *((unsigned int *)t136);
    *((unsigned int *)t136) = (t167 & t163);
    goto LAB83;

LAB84:    xsi_set_current_line(185, ng0);

LAB87:    xsi_set_current_line(186, ng0);
    t174 = (t0 + 3912);
    t175 = (t174 + 56U);
    t176 = *((char **)t175);
    t177 = (t0 + 4072);
    xsi_vlogvar_assign_value(t177, t176, 0, 0, 5);
    xsi_set_current_line(187, ng0);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 3592);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 5);
    goto LAB86;

LAB90:    *((unsigned int *)t8) = 1;
    goto LAB92;

LAB91:    t9 = (t8 + 4);
    *((unsigned int *)t8) = 1;
    *((unsigned int *)t9) = 1;
    goto LAB92;

LAB93:    *((unsigned int *)t12) = 1;
    goto LAB96;

LAB95:    t11 = (t12 + 4);
    *((unsigned int *)t12) = 1;
    *((unsigned int *)t11) = 1;
    goto LAB96;

LAB97:    t19 = (t0 + 4232);
    t20 = (t19 + 56U);
    t24 = *((char **)t20);
    t25 = ((char*)((ng2)));
    memset(t28, 0, 8);
    t26 = (t24 + 4);
    t27 = (t25 + 4);
    t46 = *((unsigned int *)t24);
    t47 = *((unsigned int *)t25);
    t48 = (t46 ^ t47);
    t49 = *((unsigned int *)t26);
    t50 = *((unsigned int *)t27);
    t53 = (t49 ^ t50);
    t54 = (t48 | t53);
    t55 = *((unsigned int *)t26);
    t59 = *((unsigned int *)t27);
    t60 = (t55 | t59);
    t61 = (~(t60));
    t62 = (t54 & t61);
    if (t62 != 0)
        goto LAB101;

LAB100:    if (t60 != 0)
        goto LAB102;

LAB103:    memset(t44, 0, 8);
    t30 = (t28 + 4);
    t63 = *((unsigned int *)t30);
    t64 = (~(t63));
    t65 = *((unsigned int *)t28);
    t68 = (t65 & t64);
    t69 = (t68 & 1U);
    if (t69 != 0)
        goto LAB104;

LAB105:    if (*((unsigned int *)t30) != 0)
        goto LAB106;

LAB107:    t70 = *((unsigned int *)t12);
    t71 = *((unsigned int *)t44);
    t72 = (t70 & t71);
    *((unsigned int *)t52) = t72;
    t45 = (t12 + 4);
    t51 = (t44 + 4);
    t56 = (t52 + 4);
    t73 = *((unsigned int *)t45);
    t74 = *((unsigned int *)t51);
    t75 = (t73 | t74);
    *((unsigned int *)t56) = t75;
    t78 = *((unsigned int *)t56);
    t79 = (t78 != 0);
    if (t79 == 1)
        goto LAB108;

LAB109:
LAB110:    goto LAB99;

LAB101:    *((unsigned int *)t28) = 1;
    goto LAB103;

LAB102:    t29 = (t28 + 4);
    *((unsigned int *)t28) = 1;
    *((unsigned int *)t29) = 1;
    goto LAB103;

LAB104:    *((unsigned int *)t44) = 1;
    goto LAB107;

LAB106:    t43 = (t44 + 4);
    *((unsigned int *)t44) = 1;
    *((unsigned int *)t43) = 1;
    goto LAB107;

LAB108:    t80 = *((unsigned int *)t52);
    t81 = *((unsigned int *)t56);
    *((unsigned int *)t52) = (t80 | t81);
    t57 = (t12 + 4);
    t58 = (t44 + 4);
    t82 = *((unsigned int *)t12);
    t83 = (~(t82));
    t85 = *((unsigned int *)t57);
    t86 = (~(t85));
    t87 = *((unsigned int *)t44);
    t88 = (~(t87));
    t89 = *((unsigned int *)t58);
    t98 = (~(t89));
    t76 = (t83 & t86);
    t77 = (t88 & t98);
    t99 = (~(t76));
    t100 = (~(t77));
    t101 = *((unsigned int *)t56);
    *((unsigned int *)t56) = (t101 & t99);
    t102 = *((unsigned int *)t56);
    *((unsigned int *)t56) = (t102 & t100);
    t105 = *((unsigned int *)t52);
    *((unsigned int *)t52) = (t105 & t99);
    t106 = *((unsigned int *)t52);
    *((unsigned int *)t52) = (t106 & t100);
    goto LAB110;

LAB111:    *((unsigned int *)t94) = 1;
    goto LAB114;

LAB113:    t67 = (t94 + 4);
    *((unsigned int *)t94) = 1;
    *((unsigned int *)t67) = 1;
    goto LAB114;

LAB115:    t90 = (t0 + 4072);
    t91 = (t90 + 56U);
    t92 = *((char **)t91);
    t93 = (t0 + 4232);
    t95 = (t93 + 56U);
    t97 = *((char **)t95);
    memset(t96, 0, 8);
    t103 = (t92 + 4);
    t104 = (t97 + 4);
    t122 = *((unsigned int *)t92);
    t123 = *((unsigned int *)t97);
    t124 = (t122 ^ t123);
    t125 = *((unsigned int *)t103);
    t126 = *((unsigned int *)t104);
    t130 = (t125 ^ t126);
    t131 = (t124 | t130);
    t132 = *((unsigned int *)t103);
    t133 = *((unsigned int *)t104);
    t134 = (t132 | t133);
    t137 = (~(t134));
    t138 = (t131 & t137);
    if (t138 != 0)
        goto LAB119;

LAB118:    if (t134 != 0)
        goto LAB120;

LAB121:    memset(t112, 0, 8);
    t109 = (t96 + 4);
    t139 = *((unsigned int *)t109);
    t143 = (~(t139));
    t144 = *((unsigned int *)t96);
    t145 = (t144 & t143);
    t146 = (t145 & 1U);
    if (t146 != 0)
        goto LAB122;

LAB123:    if (*((unsigned int *)t109) != 0)
        goto LAB124;

LAB125:    t147 = *((unsigned int *)t94);
    t148 = *((unsigned int *)t112);
    t149 = (t147 & t148);
    *((unsigned int *)t128) = t149;
    t111 = (t94 + 4);
    t113 = (t112 + 4);
    t114 = (t128 + 4);
    t152 = *((unsigned int *)t111);
    t153 = *((unsigned int *)t113);
    t154 = (t152 | t153);
    *((unsigned int *)t114) = t154;
    t155 = *((unsigned int *)t114);
    t156 = (t155 != 0);
    if (t156 == 1)
        goto LAB126;

LAB127:
LAB128:    goto LAB117;

LAB119:    *((unsigned int *)t96) = 1;
    goto LAB121;

LAB120:    t108 = (t96 + 4);
    *((unsigned int *)t96) = 1;
    *((unsigned int *)t108) = 1;
    goto LAB121;

LAB122:    *((unsigned int *)t112) = 1;
    goto LAB125;

LAB124:    t110 = (t112 + 4);
    *((unsigned int *)t112) = 1;
    *((unsigned int *)t110) = 1;
    goto LAB125;

LAB126:    t157 = *((unsigned int *)t128);
    t158 = *((unsigned int *)t114);
    *((unsigned int *)t128) = (t157 | t158);
    t127 = (t94 + 4);
    t129 = (t112 + 4);
    t159 = *((unsigned int *)t94);
    t162 = (~(t159));
    t163 = *((unsigned int *)t127);
    t164 = (~(t163));
    t165 = *((unsigned int *)t112);
    t166 = (~(t165));
    t167 = *((unsigned int *)t129);
    t169 = (~(t167));
    t160 = (t162 & t164);
    t161 = (t166 & t169);
    t170 = (~(t160));
    t171 = (~(t161));
    t172 = *((unsigned int *)t114);
    *((unsigned int *)t114) = (t172 & t170);
    t173 = *((unsigned int *)t114);
    *((unsigned int *)t114) = (t173 & t171);
    t178 = *((unsigned int *)t128);
    *((unsigned int *)t128) = (t178 & t170);
    t179 = *((unsigned int *)t128);
    *((unsigned int *)t128) = (t179 & t171);
    goto LAB128;

LAB129:    *((unsigned int *)t136) = 1;
    goto LAB132;

LAB131:    t140 = (t136 + 4);
    *((unsigned int *)t136) = 1;
    *((unsigned int *)t140) = 1;
    goto LAB132;

LAB133:    t142 = (t0 + 4072);
    t150 = (t142 + 56U);
    t151 = *((char **)t150);
    t168 = ((char*)((ng2)));
    memset(t189, 0, 8);
    t174 = (t151 + 4);
    t175 = (t168 + 4);
    t190 = *((unsigned int *)t151);
    t191 = *((unsigned int *)t168);
    t192 = (t190 ^ t191);
    t193 = *((unsigned int *)t174);
    t194 = *((unsigned int *)t175);
    t195 = (t193 ^ t194);
    t196 = (t192 | t195);
    t197 = *((unsigned int *)t174);
    t198 = *((unsigned int *)t175);
    t199 = (t197 | t198);
    t200 = (~(t199));
    t201 = (t196 & t200);
    if (t201 != 0)
        goto LAB137;

LAB136:    if (t199 != 0)
        goto LAB138;

LAB139:    memset(t202, 0, 8);
    t177 = (t189 + 4);
    t203 = *((unsigned int *)t177);
    t204 = (~(t203));
    t205 = *((unsigned int *)t189);
    t206 = (t205 & t204);
    t207 = (t206 & 1U);
    if (t207 != 0)
        goto LAB140;

LAB141:    if (*((unsigned int *)t177) != 0)
        goto LAB142;

LAB143:    t209 = (t202 + 4);
    t210 = *((unsigned int *)t202);
    t211 = *((unsigned int *)t209);
    t212 = (t210 || t211);
    if (t212 > 0)
        goto LAB144;

LAB145:    memcpy(t241, t202, 8);

LAB146:    memset(t273, 0, 8);
    t274 = (t241 + 4);
    t275 = *((unsigned int *)t274);
    t276 = (~(t275));
    t277 = *((unsigned int *)t241);
    t278 = (t277 & t276);
    t279 = (t278 & 1U);
    if (t279 != 0)
        goto LAB158;

LAB159:    if (*((unsigned int *)t274) != 0)
        goto LAB160;

LAB161:    t281 = (t273 + 4);
    t282 = *((unsigned int *)t273);
    t283 = *((unsigned int *)t281);
    t284 = (t282 || t283);
    if (t284 > 0)
        goto LAB162;

LAB163:    memcpy(t313, t273, 8);

LAB164:    memset(t345, 0, 8);
    t346 = (t313 + 4);
    t347 = *((unsigned int *)t346);
    t348 = (~(t347));
    t349 = *((unsigned int *)t313);
    t350 = (t349 & t348);
    t351 = (t350 & 1U);
    if (t351 != 0)
        goto LAB176;

LAB177:    if (*((unsigned int *)t346) != 0)
        goto LAB178;

LAB179:    t354 = *((unsigned int *)t136);
    t355 = *((unsigned int *)t345);
    t356 = (t354 | t355);
    *((unsigned int *)t353) = t356;
    t357 = (t136 + 4);
    t358 = (t345 + 4);
    t359 = (t353 + 4);
    t360 = *((unsigned int *)t357);
    t361 = *((unsigned int *)t358);
    t362 = (t360 | t361);
    *((unsigned int *)t359) = t362;
    t363 = *((unsigned int *)t359);
    t364 = (t363 != 0);
    if (t364 == 1)
        goto LAB180;

LAB181:
LAB182:    goto LAB135;

LAB137:    *((unsigned int *)t189) = 1;
    goto LAB139;

LAB138:    t176 = (t189 + 4);
    *((unsigned int *)t189) = 1;
    *((unsigned int *)t176) = 1;
    goto LAB139;

LAB140:    *((unsigned int *)t202) = 1;
    goto LAB143;

LAB142:    t208 = (t202 + 4);
    *((unsigned int *)t202) = 1;
    *((unsigned int *)t208) = 1;
    goto LAB143;

LAB144:    t213 = (t0 + 4232);
    t214 = (t213 + 56U);
    t215 = *((char **)t214);
    t216 = ((char*)((ng2)));
    memset(t217, 0, 8);
    t218 = (t215 + 4);
    t219 = (t216 + 4);
    t220 = *((unsigned int *)t215);
    t221 = *((unsigned int *)t216);
    t222 = (t220 ^ t221);
    t223 = *((unsigned int *)t218);
    t224 = *((unsigned int *)t219);
    t225 = (t223 ^ t224);
    t226 = (t222 | t225);
    t227 = *((unsigned int *)t218);
    t228 = *((unsigned int *)t219);
    t229 = (t227 | t228);
    t230 = (~(t229));
    t231 = (t226 & t230);
    if (t231 != 0)
        goto LAB148;

LAB147:    if (t229 != 0)
        goto LAB149;

LAB150:    memset(t233, 0, 8);
    t234 = (t217 + 4);
    t235 = *((unsigned int *)t234);
    t236 = (~(t235));
    t237 = *((unsigned int *)t217);
    t238 = (t237 & t236);
    t239 = (t238 & 1U);
    if (t239 != 0)
        goto LAB151;

LAB152:    if (*((unsigned int *)t234) != 0)
        goto LAB153;

LAB154:    t242 = *((unsigned int *)t202);
    t243 = *((unsigned int *)t233);
    t244 = (t242 & t243);
    *((unsigned int *)t241) = t244;
    t245 = (t202 + 4);
    t246 = (t233 + 4);
    t247 = (t241 + 4);
    t248 = *((unsigned int *)t245);
    t249 = *((unsigned int *)t246);
    t250 = (t248 | t249);
    *((unsigned int *)t247) = t250;
    t251 = *((unsigned int *)t247);
    t252 = (t251 != 0);
    if (t252 == 1)
        goto LAB155;

LAB156:
LAB157:    goto LAB146;

LAB148:    *((unsigned int *)t217) = 1;
    goto LAB150;

LAB149:    t232 = (t217 + 4);
    *((unsigned int *)t217) = 1;
    *((unsigned int *)t232) = 1;
    goto LAB150;

LAB151:    *((unsigned int *)t233) = 1;
    goto LAB154;

LAB153:    t240 = (t233 + 4);
    *((unsigned int *)t233) = 1;
    *((unsigned int *)t240) = 1;
    goto LAB154;

LAB155:    t253 = *((unsigned int *)t241);
    t254 = *((unsigned int *)t247);
    *((unsigned int *)t241) = (t253 | t254);
    t255 = (t202 + 4);
    t256 = (t233 + 4);
    t257 = *((unsigned int *)t202);
    t258 = (~(t257));
    t259 = *((unsigned int *)t255);
    t260 = (~(t259));
    t261 = *((unsigned int *)t233);
    t262 = (~(t261));
    t263 = *((unsigned int *)t256);
    t264 = (~(t263));
    t265 = (t258 & t260);
    t266 = (t262 & t264);
    t267 = (~(t265));
    t268 = (~(t266));
    t269 = *((unsigned int *)t247);
    *((unsigned int *)t247) = (t269 & t267);
    t270 = *((unsigned int *)t247);
    *((unsigned int *)t247) = (t270 & t268);
    t271 = *((unsigned int *)t241);
    *((unsigned int *)t241) = (t271 & t267);
    t272 = *((unsigned int *)t241);
    *((unsigned int *)t241) = (t272 & t268);
    goto LAB157;

LAB158:    *((unsigned int *)t273) = 1;
    goto LAB161;

LAB160:    t280 = (t273 + 4);
    *((unsigned int *)t273) = 1;
    *((unsigned int *)t280) = 1;
    goto LAB161;

LAB162:    t285 = (t0 + 4552);
    t286 = (t285 + 56U);
    t287 = *((char **)t286);
    t288 = ((char*)((ng3)));
    memset(t289, 0, 8);
    t290 = (t287 + 4);
    t291 = (t288 + 4);
    t292 = *((unsigned int *)t287);
    t293 = *((unsigned int *)t288);
    t294 = (t292 ^ t293);
    t295 = *((unsigned int *)t290);
    t296 = *((unsigned int *)t291);
    t297 = (t295 ^ t296);
    t298 = (t294 | t297);
    t299 = *((unsigned int *)t290);
    t300 = *((unsigned int *)t291);
    t301 = (t299 | t300);
    t302 = (~(t301));
    t303 = (t298 & t302);
    if (t303 != 0)
        goto LAB168;

LAB165:    if (t301 != 0)
        goto LAB167;

LAB166:    *((unsigned int *)t289) = 1;

LAB168:    memset(t305, 0, 8);
    t306 = (t289 + 4);
    t307 = *((unsigned int *)t306);
    t308 = (~(t307));
    t309 = *((unsigned int *)t289);
    t310 = (t309 & t308);
    t311 = (t310 & 1U);
    if (t311 != 0)
        goto LAB169;

LAB170:    if (*((unsigned int *)t306) != 0)
        goto LAB171;

LAB172:    t314 = *((unsigned int *)t273);
    t315 = *((unsigned int *)t305);
    t316 = (t314 & t315);
    *((unsigned int *)t313) = t316;
    t317 = (t273 + 4);
    t318 = (t305 + 4);
    t319 = (t313 + 4);
    t320 = *((unsigned int *)t317);
    t321 = *((unsigned int *)t318);
    t322 = (t320 | t321);
    *((unsigned int *)t319) = t322;
    t323 = *((unsigned int *)t319);
    t324 = (t323 != 0);
    if (t324 == 1)
        goto LAB173;

LAB174:
LAB175:    goto LAB164;

LAB167:    t304 = (t289 + 4);
    *((unsigned int *)t289) = 1;
    *((unsigned int *)t304) = 1;
    goto LAB168;

LAB169:    *((unsigned int *)t305) = 1;
    goto LAB172;

LAB171:    t312 = (t305 + 4);
    *((unsigned int *)t305) = 1;
    *((unsigned int *)t312) = 1;
    goto LAB172;

LAB173:    t325 = *((unsigned int *)t313);
    t326 = *((unsigned int *)t319);
    *((unsigned int *)t313) = (t325 | t326);
    t327 = (t273 + 4);
    t328 = (t305 + 4);
    t329 = *((unsigned int *)t273);
    t330 = (~(t329));
    t331 = *((unsigned int *)t327);
    t332 = (~(t331));
    t333 = *((unsigned int *)t305);
    t334 = (~(t333));
    t335 = *((unsigned int *)t328);
    t336 = (~(t335));
    t337 = (t330 & t332);
    t338 = (t334 & t336);
    t339 = (~(t337));
    t340 = (~(t338));
    t341 = *((unsigned int *)t319);
    *((unsigned int *)t319) = (t341 & t339);
    t342 = *((unsigned int *)t319);
    *((unsigned int *)t319) = (t342 & t340);
    t343 = *((unsigned int *)t313);
    *((unsigned int *)t313) = (t343 & t339);
    t344 = *((unsigned int *)t313);
    *((unsigned int *)t313) = (t344 & t340);
    goto LAB175;

LAB176:    *((unsigned int *)t345) = 1;
    goto LAB179;

LAB178:    t352 = (t345 + 4);
    *((unsigned int *)t345) = 1;
    *((unsigned int *)t352) = 1;
    goto LAB179;

LAB180:    t365 = *((unsigned int *)t353);
    t366 = *((unsigned int *)t359);
    *((unsigned int *)t353) = (t365 | t366);
    t367 = (t136 + 4);
    t368 = (t345 + 4);
    t369 = *((unsigned int *)t367);
    t370 = (~(t369));
    t371 = *((unsigned int *)t136);
    t372 = (t371 & t370);
    t373 = *((unsigned int *)t368);
    t374 = (~(t373));
    t375 = *((unsigned int *)t345);
    t376 = (t375 & t374);
    t377 = (~(t372));
    t378 = (~(t376));
    t379 = *((unsigned int *)t359);
    *((unsigned int *)t359) = (t379 & t377);
    t380 = *((unsigned int *)t359);
    *((unsigned int *)t359) = (t380 & t378);
    goto LAB182;

LAB183:    xsi_set_current_line(196, ng0);

LAB186:    xsi_set_current_line(197, ng0);
    t387 = (t0 + 4072);
    t388 = (t387 + 56U);
    t389 = *((char **)t388);
    t390 = (t0 + 4232);
    t391 = (t390 + 56U);
    t392 = *((char **)t391);
    memset(t393, 0, 8);
    xsi_vlog_unsigned_add(t393, 5, t389, 5, t392, 5);
    t394 = (t0 + 4392);
    xsi_vlogvar_assign_value(t394, t393, 0, 0, 5);
    goto LAB185;

LAB189:    t9 = (t8 + 4);
    *((unsigned int *)t8) = 1;
    *((unsigned int *)t9) = 1;
    goto LAB190;

LAB191:    xsi_set_current_line(201, ng0);

LAB194:    xsi_set_current_line(202, ng0);
    t11 = ((char*)((ng2)));
    t13 = (t0 + 4392);
    xsi_vlogvar_assign_value(t13, t11, 0, 0, 5);
    xsi_set_current_line(203, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 4072);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 5);
    xsi_set_current_line(204, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 4232);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 5);
    xsi_set_current_line(205, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 3592);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 5);
    xsi_set_current_line(206, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 4552);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 5);
    goto LAB193;

LAB197:    t9 = (t8 + 4);
    *((unsigned int *)t8) = 1;
    *((unsigned int *)t9) = 1;
    goto LAB198;

LAB199:    xsi_set_current_line(209, ng0);
    t11 = ((char*)((ng3)));
    t13 = (t0 + 4552);
    xsi_vlogvar_assign_value(t13, t11, 0, 0, 5);
    goto LAB201;

}

static void Cont_214_6(char *t0)
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

LAB0:    t1 = (t0 + 6960U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(214, ng0);
    t2 = (t0 + 3432);
    t5 = (t2 + 56U);
    t6 = *((char **)t5);
    t7 = (t0 + 3272);
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

LAB20:    t43 = (t0 + 7984);
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
    t56 = (t0 + 7872);
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

LAB12:    t37 = ((char*)((ng22)));
    goto LAB13;

LAB14:    t42 = ((char*)((ng23)));
    goto LAB15;

LAB16:    xsi_vlog_unsigned_bit_combine(t3, 32, t37, 32, t42, 32);
    goto LAB20;

LAB18:    memcpy(t3, t37, 8);
    goto LAB20;

}

static void Cont_217_7(char *t0)
{
    char t3[8];
    char t4[8];
    char *t1;
    char *t2;
    char *t5;
    char *t6;
    char *t7;
    char *t8;
    char *t9;
    unsigned int t10;
    unsigned int t11;
    unsigned int t12;
    unsigned int t13;
    unsigned int t14;
    unsigned int t15;
    char *t16;
    char *t17;
    char *t18;
    char *t19;
    char *t20;
    unsigned int t21;
    unsigned int t22;
    char *t23;
    unsigned int t24;
    unsigned int t25;
    char *t26;
    unsigned int t27;
    unsigned int t28;
    char *t29;

LAB0:    t1 = (t0 + 7208U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(217, ng0);
    t2 = ((char*)((ng2)));
    t5 = (t0 + 4392);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    memset(t4, 0, 8);
    t8 = (t4 + 4);
    t9 = (t7 + 4);
    t10 = *((unsigned int *)t7);
    t11 = (t10 >> 0);
    *((unsigned int *)t4) = t11;
    t12 = *((unsigned int *)t9);
    t13 = (t12 >> 0);
    *((unsigned int *)t8) = t13;
    t14 = *((unsigned int *)t4);
    *((unsigned int *)t4) = (t14 & 31U);
    t15 = *((unsigned int *)t8);
    *((unsigned int *)t8) = (t15 & 31U);
    xsi_vlogtype_concat(t3, 8, 8, 2U, t4, 5, t2, 3);
    t16 = (t0 + 8048);
    t17 = (t16 + 56U);
    t18 = *((char **)t17);
    t19 = (t18 + 56U);
    t20 = *((char **)t19);
    memset(t20, 0, 8);
    t21 = 255U;
    t22 = t21;
    t23 = (t3 + 4);
    t24 = *((unsigned int *)t3);
    t21 = (t21 & t24);
    t25 = *((unsigned int *)t23);
    t22 = (t22 & t25);
    t26 = (t20 + 4);
    t27 = *((unsigned int *)t20);
    *((unsigned int *)t20) = (t27 | t21);
    t28 = *((unsigned int *)t26);
    *((unsigned int *)t26) = (t28 | t22);
    xsi_driver_vfirst_trans(t16, 0, 7);
    t29 = (t0 + 7888);
    *((int *)t29) = 1;

LAB1:    return;
}

static void Always_219_8(char *t0)
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

LAB0:    t1 = (t0 + 7456U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(219, ng0);
    t2 = (t0 + 7904);
    *((int *)t2) = 1;
    t3 = (t0 + 7488);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(220, ng0);
    t4 = (t0 + 3912);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = ((char*)((ng12)));
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

LAB10:    xsi_set_current_line(223, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 2632);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 1, 0LL);

LAB11:    goto LAB2;

LAB7:    t23 = (t8 + 4);
    *((unsigned int *)t8) = 1;
    *((unsigned int *)t23) = 1;
    goto LAB8;

LAB9:    xsi_set_current_line(221, ng0);
    t30 = ((char*)((ng3)));
    t31 = (t0 + 2632);
    xsi_vlogvar_wait_assign_value(t31, t30, 0, 0, 1, 0LL);
    goto LAB11;

}


extern void work_m_00000000001721120979_1026299294_init()
{
	static char *pe[] = {(void *)Always_42_0,(void *)Always_56_1,(void *)Always_86_2,(void *)Always_150_3,(void *)Always_156_4,(void *)Always_170_5,(void *)Cont_214_6,(void *)Cont_217_7,(void *)Always_219_8};
	xsi_register_didat("work_m_00000000001721120979_1026299294", "isim/button_tb_isim_beh.exe.sim/work/m_00000000001721120979_1026299294.didat");
	xsi_register_executes(pe);
}
