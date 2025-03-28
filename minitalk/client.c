/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-26 17:05:05 by edugonza          #+#    #+#             */
/*   Updated: 2025-02-26 17:05:05 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

static void	send_signal(char *str, int server_pid)
{
	unsigned long	i;
	unsigned long	j;
	unsigned char	byte;

	i = 0;
	usleep(500);
	while (str[i] != '\0')
	{
		j = 0;
		while (j < 8)
		{
			byte = str[i] >> (7 - j) & 1;
			usleep(500);
			if (byte == 0)
				kill(server_pid, SIGUSR1);
			if (byte == 1)
				kill(server_pid, SIGUSR2);
			j++;
		}
		i++;
	}
	return ;
}

static void	ack_handler(int signum)
{
	if (signum == SIGUSR1)
		ft_printf("Client got acknowledgment!\n");
}

static char	*fill_with_zeros(char *str)
{
	int		s;
	char	*new_str1;
	char	*new_str2;

	new_str1 = str;
	s = ft_strlen(str);
	while (s < 32)
	{
		new_str2 = ft_strjoin("0", new_str1);
		free(new_str1);
		new_str1 = new_str2;
		s++;
	}
	return (new_str1);
}

static int	send_size(char *str, int server_pid)
{
	int		size;
	int		j;
	char	*string_size;
	char	*size_binary;

	size = ft_strlen(str);
	string_size = ft_itoa(size);
	size_binary = fill_with_zeros(
			ft_convert_base(string_size, "0123456789", "01"));
	j = 0;
	while (j < 32)
	{
		usleep(500);
		if (size_binary[j] == '0')
			kill(server_pid, SIGUSR1);
		if (size_binary[j] == '1')
			kill(server_pid, SIGUSR2);
		j++;
	}
	free(size_binary);
	free(string_size);
	return (size);
}

int	main(int ac, char **av)
{
	int	size;
	int	server_pid;

	if (ac < 3)
	{
		ft_printf("Usage: <./client> <server_pid> ");
		ft_printf("<'message in single quotes'>\n");
		return (1);
	}
	server_pid = ft_atoi(av[1]);
	if (!server_pid)
	{
		ft_printf("Server PID must be a non-zero number\n");
		return (1);
	}
	size = send_size(av[2], server_pid);
	send_signal(av[2], server_pid);
	signal(SIGUSR1, ack_handler);
	pause();
	return (0);
}

/*
 ./client <pid> '¡Hola! こんにちは 🌟 Testing 123! @#$%^&*()_+-=[]{}|;:,.<>? 
 RandomString123 🚀 UnicodeMix 🎉 Привет世界! ~`!@#$%^&*()_+-=[]{}|;:,.<>? 
 4567890 😊🐱🚀🌍🎸 "!@#$%^&*()_+-=[]{}|;:,.<>? qwertyuiopasdfghjklzxcvbnm 
 QWERTYUIOPASDFGHJKLZXCVBNM 0987654321 🌟🌙🌞🌍🌎🌏🌠🌡️🍎🍌🍒🍕🍔🍟🍦🍰🎂
 🎃🎄🎅🎁🎈🎉🎊🎋🎌🎍🎎🎏🎐🎑🎒🎓🎖️🎗️🎙️🎚️🎛️🎜🎝🎞️🎟️🎠🎡🎢🎣🎤🎥🎦🎧🎨🎩🎪
 🎫🎬🎭🎮🎯🎰🎱🎲🎳🎴🎵🎶🎷🎸🎹🎺🎻🎼🎽🎾🎿🏀🏁🏂🏃🏄🏅🏆🏇🏈🏉🏊🏋️🏌️🏍️
 🏎️🏏🏐🏑🏒🏓🏔️🏕️🏖️🏗️🏘️🏙️🏚️🏛️🏜️🏝️🏞️🏟️🏠🏡🏢🏣🏤🏥🏦🏧🏨🏩🏪🏫🏬🏭🏮🏯🏰🏱🏲
 🏳️🏴🏵️🏶🏷️🏸🏹🏺🏻🏼🏽🏾🏿🐀🐁🐂🐃🐄🐅🐆🐇🐈🐉🐊🐋🐌🐍🐎🐏🐐🐑🐒🐓🐔🐕🐖
 🐗🐘🐙🐚🐛🐜🐝🐞🐟🐠🐡🐢🐣🐤🐥🐦🐧🐨🐩🐪🐫🐬🐭🐮🐯🐰🐱🐲🐳🐴🐵🐶🐷🐸🐹🐺
 🐻🐼🐽🐾🐿️👀👁️👂👃👄👅👆👇👈👉👊👋👌👍👎👏👐👑👒👓👔👕👖👗👘👙👚👛👜👝👞
 👟👠👡👢👣👤👥👦👧👨👩👪👫👬👭👮👯👰👱👲👳👴👵👶👷👸👹👺👻👼👽👾👿💀💁💂
 💃💄💅💆💇💈💉💊💋💌💍💎💏💐💑💒💓💔💕💖💗💘💙💚💛💜💝💞💟💠💡💢💣💤💥💦
 💧💨💩💪💫💬💭💮💯💰💱💲💳💴💵💶💷💸💹💺💻💼💽💾💿📀📁📂📃📄📅📆📇📈📉📊
 📋📌📍📎📏📐📑📒📓📔📕📖📗📘📙📚📛📜📝📞📟📠📡📢📣📤📥📦📧📨📩📪📫📬📭📮
 📯📰📱📲📳📴📵📶📷📸📹📺📻📼📽️📾🔀🔁🔂🔃🔄🔅🔆🔇🔈🔉🔊🔋🔌🔍🔎🔏🔐🔑🔒🔓
 🔔🔕🔖🔗🔘🔙🔚🔛🔜🔝🔞🔟🔠🔡🔢🔣🔤🔥🔦🔧🔨🔩🔪🔫🔬🔭🔮🔯🔰🔱🔲🔳🔴🔵🔶🔷
 🔸🔹🔺🔻🔼🔽🕉️🕊️🕋🕍🕎🕐🕑🕒🕓🕔🕕🕖🕗🕘🕙🕚🕛🕜🕝🕞🕟🕠🕡🕢🕣🕤🕥🕦🕧🕯️
 🕰️🕱🕲🕳🕴🕵🕶🕷🕸🕹🕺🖀🖁🖂🖃🖄🖅🖆🖇🖈🖉🖊🖋🖌🖍🖎🖏🖐🖑🖒🖓🖔🖕🖖🖗🖘🖙🖚🖛🖜🖝🖞🖟🖠🖡🖢🖣🖤🖥🖦🖧🖨🖩🖪🖫🖬🖭🖮🖯
 🖰🖱🖲🖳🖴🖵🖶🖷🖸🖹🖺🖻🖼🖽🖾🖿🗀🗁🗂🗃🗄🗅🗆🗇🗈🗉🗊🗋🗌🗍🗎🗏🗐🗑🗒🗓🗔🗕🗖🗗🗘🗙🗚🗛🗜🗝🗞🗟🗠🗡🗢🗣🗤🗥🗦🗧🗨🗩🗪🗫🗬🗭🗮🗯🗰🗱🗲🗳🗴🗵🗶🗷🗸🗹
 🗺🗻🗼🗽🗾🗿'

 */
