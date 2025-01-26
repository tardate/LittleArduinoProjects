require 'spec_helper'
require 'examples'

describe my_function do
  it 'will sometimes fail!' do
    expect(subject).to eql(2)
  end
end
