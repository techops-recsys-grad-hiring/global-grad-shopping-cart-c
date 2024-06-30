project(
  'joi-c',
  'c',
  default_options: [
    'c_std=c99',
    'warning_level=3',
  ],
)

##
# Enable double precision floating point assertions:
#
# • https://github.com/ThrowTheSwitch/Unity/blob/master/docs/UnityAssertionsReference.md#double-if-enabled
# • https://github.com/ThrowTheSwitch/Unity/blob/master/docs/UnityConfigurationGuide.md
#
add_global_arguments(
  '-DUNITY_INCLUDE_FLOAT',
  '-DUNITY_INCLUDE_DOUBLE',
  language: 'c',
) 

lib_src = files('src/order.c', 'src/shopping_cart.c')
app_src = lib_src + files('src/main.c')

executable(
  'joi-grad-shopping-cart-c',
  app_src,
  c_args: '-DUNITY_INCLUDE_CONFIG_H',
)

unity_subproject = subproject('unity')
unity_dependency = unity_subproject.get_variable('unity_dep')

test_src = files('test/test_main.c', 'test/shopping_cart_test.c')

incdir = include_directories('include')

joi_tests = executable('joi-grad-shopping-cart-c-test',
  lib_src + test_src,
  dependencies: [ unity_dependency ],
  include_directories: incdir,
)

test('joi-grad-shopping-cart-c-test', joi_tests)
