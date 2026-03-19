/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 12:47:51 by edugonza          #+#    #+#             */
/*   Updated: 2026/03/16 21:44:35 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSACK_HPP
# define MUTANTSACK_HPP

#include <stack>

template <typename T>
class MutantStack : public std::stack<T> {

	private:

	public:
		typedef typename std::stack<T>::container_type::iterator iterator;
		typedef typename std::stack<T>::container_type::const_iterator const_iterator;

		iterator begin()	{ return this->c.begin(); }
		iterator end()	{ return this->c.end(); }

		/*
		iterator							=> pointer can change, value can change
		const iterator				=> pointer doesn't change, value can change
		const_iterator				=> pointer can change, value can't change
		const const_iterator	=> pointer and value can't change
		*/

		const_iterator begin()	const { return this->c.begin(); }
		const_iterator end()	const { return this->c.end(); }
};

// #include "MutantStack.tpp"

#endif

/* Stack class:

namespace std {
  template<class T, class Container = deque<T>>
  class stack
  {
  public:
    using value_type      = typename Container::value_type;
    using reference       = typename Container::reference;
    using const_reference = typename Container::const_reference;
    using size_type       = typename Container::size_type;
    using container_type  = Container;

  protected:
    Container c;

  public:
    stack()
      : stack(Container())
    {
    }
    explicit stack(const Container&);
    explicit stack(Container&&);
    template<class InputIter>
    stack(InputIter first, InputIter last);
    template<container-compatible-range<T> R>
    stack(from_range_t, R&& rg);
    template<class Alloc>
    explicit stack(const Alloc&);
    template<class Alloc>
    stack(const Container&, const Alloc&);
    template<class Alloc>
    stack(Container&&, const Alloc&);
    template<class Alloc>
    stack(const stack&, const Alloc&);
    template<class Alloc>
    stack(stack&&, const Alloc&);
    template<class InputIter, class Alloc>
    stack(InputIter first, InputIter last, const Alloc&);
    template<container-compatible-range<T> R, class Alloc>
    stack(from_range_t, R&& rg, const Alloc&);

    bool empty() const { return c.empty(); }
    size_type size() const { return c.size(); }
    reference top() { return c.back(); }
    const_reference top() const { return c.back(); }
    void push(const value_type& x) { c.push_back(x); }
    void push(value_type&& x) { c.push_back(std::move(x)); }
    template<container-compatible-range<T> R>
    void push_range(R&& rg);
    template<class... Args>
    decltype(auto) emplace(Args&&... args)
    {
      return c.emplace_back(std::forward<Args>(args)...);
    }
    void pop() { c.pop_back(); }
    void swap(stack& s) noexcept(is_nothrow_swappable_v<Container>)
    {
      using std::swap;
      swap(c, s.c);
    }
  };

  template<class Container>
  stack(Container) -> stack<typename Container::value_type, Container>;

  template<class InputIter>
  stack(InputIter, InputIter) -> stack</\*iter-value-type*\/<InputIter>>;

  template<ranges::input_range R>
  stack(from_range_t, R&&) -> stack<ranges::range_value_t<R>>;

  template<class Container, class Allocator>
  stack(Container, Allocator) -> stack<typename Container::value_type, Container>;

  template<class InputIter, class Allocator>
  stack(InputIter, InputIter, Allocator)
    -> stack</\*iter-value-type*\/<InputIter>,
             deque</\*iter-value-type*\/<InputIter>, Allocator>>;

  template<ranges::input_range R, class Allocator>
  stack(from_range_t, R&&, Allocator)
    -> stack<ranges::range_value_t<R>, deque<ranges::range_value_t<R>, Allocator>>;

  template<class T, class Container, class Alloc>
  struct uses_allocator<stack<T, Container>, Alloc>
    : uses_allocator<Container, Alloc>::type
  {};
}

*/
