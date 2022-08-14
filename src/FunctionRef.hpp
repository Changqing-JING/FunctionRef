#ifndef FUNCTION_REF_HPP
#define FUNCTION_REF_HPP
#include <functional>
#include <utility>
namespace vb {
template <typename T> class FunctionRef;

template <typename ReturnType, typename... Arguments>
class FunctionRef<ReturnType(Arguments...)> final {
public:
  template <typename FunctionType>
  FunctionRef(FunctionType &&function) noexcept
      : function(reinterpret_cast<void const *>(&function)),
        executor(templateExecutor<
                 typename std::remove_reference<FunctionType>::type>) {
    static_assert(
        std::is_convertible<FunctionType &&,
                            std::function<ReturnType(Arguments...)>>::value,
        "Wrong Function type");
  }

  ReturnType operator()(Arguments... args) const {
    return executor(function, std::forward<Arguments>(args)...);
  }

private:
  void const *function;
  ReturnType (*executor)(void const *callable, Arguments... params);

  template <typename FunctionType>
  static ReturnType templateExecutor(void const *function,
                                     Arguments... params) {
    return (*reinterpret_cast<FunctionType *>(const_cast<void *>(function)))(
        std::forward<Arguments>(params)...);
  }
};
} // namespace vb

#endif