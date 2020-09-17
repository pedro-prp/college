json.extract! movie, :id, :title, :description, :length, :director, :rating, :created_at, :updated_at
json.url movie_url(movie, format: :json)
