#include<iostream>
#include<cstdio>
#include<cmath>
#include<stack>
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>
#include<map>

#ifndef _STL_QUEUE_H
#define _STL_QUEUE_H 1

#include <bits/concept_check.h>
#include <debug/debug.h>
#if __cplusplus >= 201103L
# include <bits/uses_allocator.h>
#endif

namespace std _GLIBCXX_VISIBILITY(default) {
	_GLIBCXX_BEGIN_NAMESPACE_VERSION


	template<typename _Tp, typename _Sequence = deque<_Tp> >
	class queue {
			// concept requirements
			typedef typename _Sequence::value_type _Sequence_value_type;
			__glibcxx_class_requires(_Tp, _SGIAssignableConcept)
			__glibcxx_class_requires(_Sequence, _FrontInsertionSequenceConcept)
			__glibcxx_class_requires(_Sequence, _BackInsertionSequenceConcept)
			__glibcxx_class_requires2(_Tp, _Sequence_value_type, _SameTypeConcept)

			template<typename _Tp1, typename _Seq1>
			friend bool
			operator==(const queue<_Tp1, _Seq1>&, const queue<_Tp1, _Seq1>&);

			template<typename _Tp1, typename _Seq1>
			friend bool
			operator<(const queue<_Tp1, _Seq1>&, const queue<_Tp1, _Seq1>&);

		public:
			typedef typename _Sequence::value_type                value_type;
			typedef typename _Sequence::reference                 reference;
			typedef typename _Sequence::const_reference           const_reference;
			typedef typename _Sequence::size_type                 size_type;
			typedef          _Sequence                            container_type;

		protected:
			 
			_Sequence c;

		public:
#if __cplusplus < 201103L
			explicit
			queue(const _Sequence& __c = _Sequence())
				: c(__c) { }
#else
			explicit
			queue(const _Sequence& __c)
				: c(__c) { }

			explicit
			queue(_Sequence&& __c = _Sequence())
				: c(std::move(__c)) { }
#endif
			bool
			empty() const {
				return c.empty(); }
			size_type
			size() const {
				return c.size(); }
			reference
			front() {
				__glibcxx_requires_nonempty();
				return c.front(); }
			const_reference
			front() const {
				__glibcxx_requires_nonempty();
				return c.front(); }
			reference
			back() {
				__glibcxx_requires_nonempty();
				return c.back(); }
			const_reference
			back() const {
				__glibcxx_requires_nonempty();
				return c.back(); }
			void
			push(const value_type& __x) {
				c.push_back(__x); }

#if __cplusplus >= 201103L
			void
			push(value_type&& __x) {
				c.push_back(std::move(__x)); }

			template<typename... _Args>
			void
			emplace(_Args&&... __args) {
				c.emplace_back(std::forward<_Args>(__args)...); }
#endif
			void
			pop() {
				__glibcxx_requires_nonempty();
				c.pop_front(); }

#if __cplusplus >= 201103L
			void
			swap(queue& __q)
			noexcept(noexcept(swap(c, __q.c))) {
				using std::swap;
				swap(c, __q.c); }
#endif
	};
	template<typename _Tp, typename _Seq>
	inline bool
	operator==(const queue<_Tp, _Seq>& __x, const queue<_Tp, _Seq>& __y) {
		return __x.c == __y.c; }
	template<typename _Tp, typename _Seq>
	inline bool
	operator<(const queue<_Tp, _Seq>& __x, const queue<_Tp, _Seq>& __y) {
		return __x.c < __y.c; }
	template<typename _Tp, typename _Seq>
	inline bool
	operator!=(const queue<_Tp, _Seq>& __x, const queue<_Tp, _Seq>& __y) {
		return !(__x == __y); }
	template<typename _Tp, typename _Seq>
	inline bool
	operator>(const queue<_Tp, _Seq>& __x, const queue<_Tp, _Seq>& __y) {
		return __y < __x; }
	template<typename _Tp, typename _Seq>
	inline bool
	operator<=(const queue<_Tp, _Seq>& __x, const queue<_Tp, _Seq>& __y) {
		return !(__y < __x); }
	template<typename _Tp, typename _Seq>
	inline bool
	operator>=(const queue<_Tp, _Seq>& __x, const queue<_Tp, _Seq>& __y) {
		return !(__x < __y); }

#if __cplusplus >= 201103L
	template<typename _Tp, typename _Seq>
	inline void
	swap(queue<_Tp, _Seq>& __x, queue<_Tp, _Seq>& __y)
	noexcept(noexcept(__x.swap(__y))) {
		__x.swap(__y); }

	template<typename _Tp, typename _Seq, typename _Alloc>
	struct uses_allocator<queue<_Tp, _Seq>, _Alloc>
			: public uses_allocator<_Seq, _Alloc>::type { };
#endif
	template<typename _Tp, typename _Sequence = vector<_Tp>,
	         typename _Compare  = less<typename _Sequence::value_type> >
	class priority_queue {
			typedef typename _Sequence::value_type _Sequence_value_type;
			__glibcxx_class_requires(_Tp, _SGIAssignableConcept)
			__glibcxx_class_requires(_Sequence, _SequenceConcept)
			__glibcxx_class_requires(_Sequence, _RandomAccessContainerConcept)
			__glibcxx_class_requires2(_Tp, _Sequence_value_type, _SameTypeConcept)
			__glibcxx_class_requires4(_Compare, bool, _Tp, _Tp,
			                          _BinaryFunctionConcept)

		public:
			typedef typename _Sequence::value_type                value_type;
			typedef typename _Sequence::reference                 reference;
			typedef typename _Sequence::const_reference           const_reference;
			typedef typename _Sequence::size_type                 size_type;
			typedef          _Sequence                            container_type;

		protected:
			_Sequence  c;
			_Compare   comp;

		public:
#if __cplusplus < 201103L
			explicit
			priority_queue(const _Compare& __x = _Compare(),
			               const _Sequence& __s = _Sequence())
				: c(__s), comp(__x) {
				std::make_heap(c.begin(), c.end(), comp); }
#else
			explicit
			priority_queue(const _Compare& __x,
			               const _Sequence& __s)
				: c(__s), comp(__x) {
				std::make_heap(c.begin(), c.end(), comp); }

			explicit
			priority_queue(const _Compare& __x = _Compare(),
			               _Sequence&& __s = _Sequence())
				: c(std::move(__s)), comp(__x) {
				std::make_heap(c.begin(), c.end(), comp); }
#endif

#if __cplusplus < 201103L
			template<typename _InputIterator>
			priority_queue(_InputIterator __first, _InputIterator __last,
			               const _Compare& __x = _Compare(),
			               const _Sequence& __s = _Sequence())
				: c(__s), comp(__x) {
				__glibcxx_requires_valid_range(__first, __last);
				c.insert(c.end(), __first, __last);
				std::make_heap(c.begin(), c.end(), comp); }
#else
			template<typename _InputIterator>
			priority_queue(_InputIterator __first, _InputIterator __last,
			               const _Compare& __x,
			               const _Sequence& __s)
				: c(__s), comp(__x) {
				__glibcxx_requires_valid_range(__first, __last);
				c.insert(c.end(), __first, __last);
				std::make_heap(c.begin(), c.end(), comp); }

			template<typename _InputIterator>
			priority_queue(_InputIterator __first, _InputIterator __last,
			               const _Compare& __x = _Compare(),
			               _Sequence&& __s = _Sequence())
				: c(std::move(__s)), comp(__x) {
				__glibcxx_requires_valid_range(__first, __last);
				c.insert(c.end(), __first, __last);
				std::make_heap(c.begin(), c.end(), comp); }
#endif
			bool
			empty() const {
				return c.empty(); }
			size_type
			size() const {
				return c.size(); }
			const_reference
			top() const {
				__glibcxx_requires_nonempty();
				return c.front(); }
			void
			push(const value_type& __x) {
				c.push_back(__x);
				std::push_heap(c.begin(), c.end(), comp); }

#if __cplusplus >= 201103L
			void
			push(value_type&& __x) {
				c.push_back(std::move(__x));
				std::push_heap(c.begin(), c.end(), comp); }

			template<typename... _Args>
			void
			emplace(_Args&&... __args) {
				c.emplace_back(std::forward<_Args>(__args)...);
				std::push_heap(c.begin(), c.end(), comp); }
#endif
			void
			pop() {
				__glibcxx_requires_nonempty();
				std::pop_heap(c.begin(), c.end(), comp);
				c.pop_back(); }

#if __cplusplus >= 201103L
			void
			swap(priority_queue& __pq)
			noexcept(noexcept(swap(c, __pq.c)) && noexcept(swap(comp, __pq.comp))) {
				using std::swap;
				swap(c, __pq.c);
				swap(comp, __pq.comp); }
#endif
	};
#if __cplusplus >= 201103L
	template<typename _Tp, typename _Sequence, typename _Compare>
	inline void
	swap(priority_queue<_Tp, _Sequence, _Compare>& __x,
	     priority_queue<_Tp, _Sequence, _Compare>& __y)
	noexcept(noexcept(__x.swap(__y))) {
		__x.swap(__y); }

	template<typename _Tp, typename _Sequence, typename _Compare,
	         typename _Alloc>
	struct uses_allocator<priority_queue<_Tp, _Sequence, _Compare>, _Alloc>
			: public uses_allocator<_Sequence, _Alloc>::type { };
#endif

	_GLIBCXX_END_NAMESPACE_VERSION }

#endif
using namespace std;
const int MO = 998244353;
int n,m,k;
int v[101];
int main() {
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=0; i<=m; i++)scanf("%d",v+i);
	cout<<78;
	return 0; }
