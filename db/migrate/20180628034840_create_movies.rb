class CreateMovies < ActiveRecord::Migration[5.2]
  def change
    create_table :movies do |t|
      t.string :title
      t.string :description
      t.string :length
      t.string :director
      t.string :rating

      t.timestamps
    end
  end
end
