/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 17:42:57 by jmagand           #+#    #+#             */
/*   Updated: 2025/12/12 13:49:55 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class PhoneBook {
private:
    Contact _contacts[8];
    int     _count;
    int     _nextIndex;

public:
    PhoneBook();
    bool addContact();
    bool searchContact() const;
};

#endif
