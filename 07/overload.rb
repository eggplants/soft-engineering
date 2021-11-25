# frozen_string_literal: true

# rbenv install 3.0.2
# rbenv global 3.0.2
# gem install overloader
require 'overloader'
require 'overloader/type'

# Good class
class Good
  extend Overloader
  overload do
    # () -> untyped
    def good() = { name: nil, price: nil }
    # (String) -> untyped
    def good(name) = { name: name, price: nil }
    # (Integer) -> untyped
    def good(price) = { name: nil, price: price }
    # (String, Integer) -> untyped
    def good(name, price) = { name: name, price: price }
    # (Integer, String) -> untyped
    def good(price, name) = { name: name, price: price }
  end
end

g = Good.new
p g.good # => {:name => nil, :price => nil}
p a.good('choco') # => {:name => "choco", :price => nil}
p a.good(100) # => {:name => nil, :price => 100}
p a.good('choco', 100) # => {:name => "choco", :price => 100}
p a.good(100, 'choco') # => {:name => "choco", :price => 100}
